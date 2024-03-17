import home from "./views/Home.js"
import about from "./views/About.js"
import contact from "./views/Contact.js"
import login from "./views/Login.js"
import main from "./views/Main.js"

let is_logged = false;

function navigateTo (url)
{
	window.history.pushState(null, null, url);
	router();
}

const router = async () => {
	const routes = [
		{path : "/", view : login},
		{path : "/about", view : about},
		{path : "/contact", view : contact},
		{path : "/home", view : home},
	];

	const path = window.location.pathname;
	let match;

	routes.forEach(route => {
		if (route.path === path)
			match = route;
	})
	
	if (match.path === "/" || !is_logged)
	{
		console.log("Calling login view ");
		document.querySelector("#app").innerHTML = login();
	}
	else if (match.path === "/about")
	{
		console.log("Calling about view ");
	    document.querySelector("#main").innerHTML = await match.view();
	}
	else
	{
		console.log("Calling other view");
	    document.querySelector("#main").innerHTML = match.view();
	}
};

window.addEventListener("popstate", () => {
//	if (location.pathname === "/")
//		window.pushState(null, null, "/home");
	router();
});

document.addEventListener("DOMContentLoaded", () => {
	document.addEventListener("click", e => {
		if (e.target.matches("[data-route]"))
		{
			e.preventDefault();
			navigateTo(e.target.href);
		}
	});

	document.addEventListener("submit", e => {
		e.preventDefault();
		const form = e.target;
		const username = form.elements.username.value;
		const password = form.elements.password.value;

		if (username === 'tito' && password === 'titi')
		{
			is_logged = true;
			document.querySelector("#app").innerHTML = main();
			console.log("Good auth !!!");
			navigateTo("/home");
		}
		else console.log("Wrong identification");
	})
	router();
});
