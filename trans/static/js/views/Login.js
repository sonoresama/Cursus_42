export default function login ()
{
	return `
	<h1> Login </h1>
	<form id="login_form">
		<input type="text" id="username" placeholder="UserName">
		<input type="text" id="password" placeholder="Password">
		<button type="submit"> Login </button>
	</form>
	`;
}
