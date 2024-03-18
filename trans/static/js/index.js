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

function checkIfLogged()
{
	// fetcvh (islogged, /api/login)
	if (!is_logged)
		navigateTo("/login");
	else
		navigateTo("/");
}

const router = async () => {
	const routes = [
		{path : "/login", view : login},
		{path : "/about", view : about},
		{path : "/contact", view : contact},
		{path : "/home", view : home},
	];

	const path = window.location.pathname;
	console.log("path : " + path);
	let match = {path : "/", view : home};

	routes.forEach(route => {
		if (route.path === path)
			match = route;
	})
	
	console.log(match.path);
	if (match.path === "/about")
	{
		console.log("Calling about view ");
	    document.querySelector("#main").innerHTML = await match.view();
	}
	else if (match.path === "/login")
	    document.querySelector("#app").innerHTML = match.view();
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

	document.addEventListener("submit", async (e) => {
		e.preventDefault();
		const form = e.target;
		const username = form.elements.username.value;
		const password = form.elements.password.value;

		const response = await fetch('http://localhost:8000/api/login/', {
			method: 'POST',
			headers: { 'Content-type' : 'application/json' },
			body: JSON.stringify({ 'username' : username , 'password' : password })
			})
		const data = response.json();
		console.log("data from Django : " + data);

		if (username === 'tito' && password === 'titi')
		{
			is_logged = true;
			document.querySelector("#app").innerHTML = main();
			console.log("Good auth !!!");
			navigateTo("/home");
		}
		else console.log("Wrong identification");
	})
	checkIfLogged();
});
