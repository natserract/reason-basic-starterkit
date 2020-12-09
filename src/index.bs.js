'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var App$ReasonReactBasicStarterkit = require("./app/app.bs.js");

ReactDOMRe.renderToElementWithId(React.createElement(App$ReasonReactBasicStarterkit.make, { }), "__reason");

/*  Not a pure module */
