'use strict';

var React = require("react");

var Utils = { };

function App(Props) {
  return React.createElement("main", undefined, React.createElement("h1", {
                  style: {
                    fontFamily: "sans-serif",
                    padding: "30px",
                    textAlign: "center"
                  }
                }, "ReasonReact Basic Starter Kit"));
}

var make = App;

exports.Utils = Utils;
exports.make = make;
/* react Not a pure module */
