'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var App$ReasonReactExamples = require("./app/app.bs.js");

ReactDOMRe.renderToElementWithId(React.createElement(App$ReasonReactExamples.make, { }), "__reason");

/*  Not a pure module */
