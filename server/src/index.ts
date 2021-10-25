import express, { Request, Response } from "express";
import expressWS, { Application } from "express-ws";

const port = process.env.PORT || 3000;
const app = express() as unknown as Application;
expressWS(app);

app.ws("/", (ws, req) => {
	ws.on("message", (msg) => {
		console.log(msg);
	});
	console.log("socket");
});

app.listen(port);
