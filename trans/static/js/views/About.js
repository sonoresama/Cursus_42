export default function about ()
{
	const html = fetch('static/templates/about.html')
		.then(response => response.text());
	return html;
}
