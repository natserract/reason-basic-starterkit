'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

var Utils = { };

function ascii_method(param) {
  return "048";
}

var Models = {
  ascii_method: ascii_method
};

function App(Props) {
  var match = React.useState((function () {
          return /* record */[
                  /* inputData */"",
                  /* outputData */""
                ];
        }));
  var setState = match[1];
  var state = match[0];
  return React.createElement("form", {
              style: {
                display: "flex",
                height: "100vh",
                alignItems: "center",
                justifyContent: "center"
              }
            }, React.createElement("textarea", {
                  className: "form-control",
                  style: {
                    height: "100%",
                    width: "100%",
                    boxSizing: "border-box"
                  },
                  placeholder: "Char",
                  type: "text",
                  value: state[/* inputData */0],
                  onChange: (function ($$event) {
                      var $$event$1 = $$event;
                      $$event$1.persist();
                      var inputValue = $$event$1.target.value;
                      var newValue = /* array */[];
                      var changedValue = inputValue.split("");
                      changedValue.length - 1 | 0;
                      Belt_Array.forEach(changedValue, (function (value) {
                              switch (value) {
                                case "0" :
                                    var ascii_code_arg = "048";
                                    var new_value_arg = newValue;
                                    var form_data_value = inputValue;
                                    new_value_arg.push(ascii_code_arg);
                                    var getValueProcessing = new_value_arg.toString();
                                    var valueRegexMatch = getValueProcessing.replace((/,/gm), " ");
                                    return Curry._1(setState, (function (param) {
                                                  return /* record */[
                                                          /* inputData */form_data_value,
                                                          /* outputData */valueRegexMatch
                                                        ];
                                                }));
                                case "1" :
                                    newValue.push("049");
                                    var getValueProcessing$1 = newValue.toString();
                                    var valueRegexMatch$1 = getValueProcessing$1.replace((/,/gm), " ");
                                    return Curry._1(setState, (function (param) {
                                                  return /* record */[
                                                          /* inputData */inputValue,
                                                          /* outputData */valueRegexMatch$1
                                                        ];
                                                }));
                                default:
                                  throw Caml_builtin_exceptions.not_found;
                              }
                            }));
                      console.log(newValue);
                      return /* () */0;
                    })
                }), React.createElement("textarea", {
                  className: "form-control",
                  style: {
                    height: "100%",
                    width: "100%",
                    boxSizing: "border-box"
                  },
                  disabled: true,
                  placeholder: "ASCII",
                  value: state[/* outputData */1]
                }, state[/* outputData */1]));
}

var make = App;

exports.Utils = Utils;
exports.Models = Models;
exports.make = make;
/* react Not a pure module */
