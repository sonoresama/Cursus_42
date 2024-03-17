export default function contact ()
{
	console.log("t'es dans contact fdp");
	const contacts = ['Tito', 'Wan', 'Marie', 'Val'];
	const template = `
	<div>
		<h1> Contacts </h1>
		${ contacts.map(name => `<p> ${name} </p>`).join('')}
	</div>
	`;
	return template;
}
