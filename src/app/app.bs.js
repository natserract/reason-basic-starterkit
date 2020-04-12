'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

var Utils = { };

var doubleQuotesChar = (/"*/g);

function ascii_method(param) {
  switch (param) {
    case /* ASCII_00 */0 :
        return "048";
    case /* ASCII_01 */1 :
        return "049";
    case /* ASCII_02 */2 :
        return "050";
    case /* ASCII_03 */3 :
        return "051";
    case /* ASCII_04 */4 :
        return "052";
    case /* ASCII_05 */5 :
        return "053";
    case /* ASCII_06 */6 :
        return "054";
    case /* ASCII_07 */7 :
        return "055";
    case /* ASCII_08 */8 :
        return "056";
    case /* ASCII_09 */9 :
        return "057";
    case /* ASCII_A */10 :
        return "065";
    case /* ASCII_B */11 :
        return "066";
    case /* ASCII_C */12 :
        return "067";
    case /* ASCII_D */13 :
        return "068";
    case /* ASCII_E */14 :
        return "069";
    case /* ASCII_F */15 :
        return "070";
    case /* ASCII_G */16 :
        return "071";
    case /* ASCII_H */17 :
        return "072";
    case /* ASCII_I */18 :
        return "073";
    case /* ASCII_J */19 :
        return "074";
    case /* ASCII_K */20 :
        return "075";
    case /* ASCII_L */21 :
        return "076";
    case /* ASCII_M */22 :
        return "077";
    case /* ASCII_N */23 :
        return "078";
    case /* ASCII_O */24 :
        return "079";
    case /* ASCII_P */25 :
        return "080";
    case /* ASCII_Q */26 :
        return "081";
    case /* ASCII_R */27 :
        return "082";
    case /* ASCII_S */28 :
        return "083";
    case /* ASCII_T */29 :
        return "084";
    case /* ASCII_U */30 :
        return "085";
    case /* ASCII_V */31 :
        return "086";
    case /* ASCII_W */32 :
        return "087";
    case /* ASCII_X */33 :
        return "088";
    case /* ASCII_Y */34 :
        return "089";
    case /* ASCII_Z */35 :
        return "090";
    case /* ASCII_a */36 :
        return "097";
    case /* ASCII_b */37 :
        return "098";
    case /* ASCII_c */38 :
        return "099";
    case /* ASCII_d */39 :
        return "0100";
    case /* ASCII_e */40 :
        return "0101";
    case /* ASCII_f */41 :
        return "0102";
    case /* ASCII_g */42 :
        return "0103";
    case /* ASCII_h */43 :
        return "0104";
    case /* ASCII_i */44 :
        return "0105";
    case /* ASCII_j */45 :
        return "0106";
    case /* ASCII_k */46 :
        return "0107";
    case /* ASCII_l */47 :
        return "0108";
    case /* ASCII_m */48 :
        return "0109";
    case /* ASCII_n */49 :
        return "0110";
    case /* ASCII_o */50 :
        return "0111";
    case /* ASCII_p */51 :
        return "0112";
    case /* ASCII_q */52 :
        return "0113";
    case /* ASCII_r */53 :
        return "0114";
    case /* ASCII_s */54 :
        return "0115";
    case /* ASCII_t */55 :
        return "0116";
    case /* ASCII_u */56 :
        return "0117";
    case /* ASCII_v */57 :
        return "0118";
    case /* ASCII_w */58 :
        return "0119";
    case /* ASCII_x */59 :
        return "0120";
    case /* ASCII_y */60 :
        return "0121";
    case /* ASCII_z */61 :
        return "0122";
    case /* ASCII_BACKSPACE */62 :
        return "032";
    case /* ASCII_KOMA */63 :
        return "044";
    case /* ASCII_TANDA_SERU */64 :
        return "033";
    case /* ASCII_DOBLE_QOTES */65 :
        return "034";
    case /* ASCII_HASTAG */66 :
        return "035";
    case /* ASCII_DOLAR */67 :
        return "036";
    case /* ASCII_PERSEN */68 :
        return "037";
    case /* ASCII_DAN */69 :
        return "038";
    case /* ASCII_SINGGEL_QUOTE */70 :
        return "039";
    case /* ASCII_KURUNG_AWAL */71 :
        return "040";
    case /* ASCII_KURUNG_AKHIR */72 :
        return "041";
    case /* ASCII_BINTANG */73 :
        return "042";
    case /* ASCII_TAMBAH */74 :
        return "043";
    case /* ASCII_KURANG */75 :
        return "045";
    case /* ASCII_TITIK */76 :
        return "046";
    case /* ASCII_SLASH */77 :
        return "047";
    case /* ASCII_SEMICOLON */78 :
        return "059";
    case /* ASCII_TITIKDUA */79 :
        return "058";
    case /* ASCII_UNDERSCORE */80 :
        return "095";
    case /* ASCII_VERTICAL_BAR */81 :
        return "124";
    case /* ASCII_SAMADENGAN */82 :
        return "061";
    case /* ASCII_AT */83 :
        return "064";
    
  }
}

var Models = {
  doubleQuotesChar: doubleQuotesChar,
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
  return React.createElement("main", undefined, React.createElement("h1", {
                  style: {
                    fontFamily: "sans-serif",
                    padding: "30px",
                    textAlign: "center"
                  }
                }, "ASCII GENERATOR"), React.createElement("form", {
                  style: {
                    display: "flex",
                    height: "100vh",
                    alignItems: "center",
                    justifyContent: "center"
                  }
                }, React.createElement("textarea", {
                      className: "form-control",
                      style: {
                        fontSize: "30px",
                        height: "100%",
                        width: "100%",
                        boxSizing: "border-box"
                      },
                      placeholder: "Char",
                      value: state[/* inputData */0],
                      onChange: (function ($$event) {
                          var $$event$1 = $$event;
                          $$event$1.persist();
                          var inputValue = $$event$1.target.value;
                          var newValue = /* array */[];
                          var changedValue = inputValue.split("");
                          changedValue.length - 1 | 0;
                          var charMethod = function (ascii_code_arg, new_value_arg, form_data_value) {
                            new_value_arg.push(ascii_code_arg);
                            var getValueProcessing = new_value_arg.toString();
                            var valueRegexMatch = getValueProcessing.replace((/,/gm), " ");
                            return Curry._1(setState, (function (param) {
                                          return /* record */[
                                                  /* inputData */form_data_value,
                                                  /* outputData */valueRegexMatch
                                                ];
                                        }));
                          };
                          return Belt_Array.forEach(changedValue, (function (value) {
                                        switch (value) {
                                          case " " :
                                              return charMethod("032", newValue, inputValue);
                                          case "!" :
                                              return charMethod("033", newValue, inputValue);
                                          case "#" :
                                              return charMethod("035", newValue, inputValue);
                                          case "$" :
                                              return charMethod("036", newValue, inputValue);
                                          case "%" :
                                              return charMethod("037", newValue, inputValue);
                                          case "&" :
                                              return charMethod("038", newValue, inputValue);
                                          case "'" :
                                              return charMethod("039", newValue, inputValue);
                                          case "(" :
                                              return charMethod("040", newValue, inputValue);
                                          case ")" :
                                              return charMethod("041", newValue, inputValue);
                                          case "*" :
                                              return charMethod("042", newValue, inputValue);
                                          case "+" :
                                              return charMethod("043", newValue, inputValue);
                                          case "," :
                                              return charMethod("044", newValue, inputValue);
                                          case "-" :
                                              return charMethod("045", newValue, inputValue);
                                          case "." :
                                              return charMethod("046", newValue, inputValue);
                                          case "/" :
                                              return charMethod("047", newValue, inputValue);
                                          case "0" :
                                              return charMethod("048", newValue, inputValue);
                                          case "1" :
                                              return charMethod("049", newValue, inputValue);
                                          case "2" :
                                              return charMethod("050", newValue, inputValue);
                                          case "3" :
                                              return charMethod("051", newValue, inputValue);
                                          case "4" :
                                              return charMethod("052", newValue, inputValue);
                                          case "5" :
                                              return charMethod("053", newValue, inputValue);
                                          case "6" :
                                              return charMethod("054", newValue, inputValue);
                                          case "7" :
                                              return charMethod("055", newValue, inputValue);
                                          case "8" :
                                              return charMethod("056", newValue, inputValue);
                                          case "9" :
                                              return charMethod("057", newValue, inputValue);
                                          case ":" :
                                              return charMethod("058", newValue, inputValue);
                                          case ";" :
                                              return charMethod("059", newValue, inputValue);
                                          case "=" :
                                              return charMethod("061", newValue, inputValue);
                                          case "@" :
                                              return charMethod("064", newValue, inputValue);
                                          case "A" :
                                              return charMethod("065", newValue, inputValue);
                                          case "B" :
                                              return charMethod("066", newValue, inputValue);
                                          case "C" :
                                              return charMethod("067", newValue, inputValue);
                                          case "D" :
                                              return charMethod("068", newValue, inputValue);
                                          case "E" :
                                              return charMethod("069", newValue, inputValue);
                                          case "F" :
                                              return charMethod("070", newValue, inputValue);
                                          case "G" :
                                              return charMethod("071", newValue, inputValue);
                                          case "H" :
                                              return charMethod("072", newValue, inputValue);
                                          case "I" :
                                              return charMethod("073", newValue, inputValue);
                                          case "J" :
                                              return charMethod("074", newValue, inputValue);
                                          case "K" :
                                              return charMethod("075", newValue, inputValue);
                                          case "L" :
                                              return charMethod("076", newValue, inputValue);
                                          case "M" :
                                              return charMethod("077", newValue, inputValue);
                                          case "N" :
                                              return charMethod("078", newValue, inputValue);
                                          case "O" :
                                              return charMethod("079", newValue, inputValue);
                                          case "P" :
                                              return charMethod("080", newValue, inputValue);
                                          case "Q" :
                                              return charMethod("081", newValue, inputValue);
                                          case "R" :
                                              return charMethod("082", newValue, inputValue);
                                          case "S" :
                                              return charMethod("083", newValue, inputValue);
                                          case "T" :
                                              return charMethod("084", newValue, inputValue);
                                          case "U" :
                                              return charMethod("085", newValue, inputValue);
                                          case "V" :
                                              return charMethod("086", newValue, inputValue);
                                          case "W" :
                                              return charMethod("087", newValue, inputValue);
                                          case "X" :
                                              return charMethod("088", newValue, inputValue);
                                          case "Y" :
                                              return charMethod("089", newValue, inputValue);
                                          case "Z" :
                                              return charMethod("090", newValue, inputValue);
                                          case "_" :
                                              return charMethod("095", newValue, inputValue);
                                          case "a" :
                                              return charMethod("097", newValue, inputValue);
                                          case "b" :
                                              return charMethod("098", newValue, inputValue);
                                          case "c" :
                                              return charMethod("099", newValue, inputValue);
                                          case "d" :
                                              return charMethod("0100", newValue, inputValue);
                                          case "e" :
                                              return charMethod("0101", newValue, inputValue);
                                          case "f" :
                                              return charMethod("0102", newValue, inputValue);
                                          case "g" :
                                              return charMethod("0103", newValue, inputValue);
                                          case "h" :
                                              return charMethod("0104", newValue, inputValue);
                                          case "i" :
                                              return charMethod("0105", newValue, inputValue);
                                          case "j" :
                                              return charMethod("0106", newValue, inputValue);
                                          case "k" :
                                              return charMethod("0107", newValue, inputValue);
                                          case "l" :
                                              return charMethod("0108", newValue, inputValue);
                                          case "m" :
                                              return charMethod("0109", newValue, inputValue);
                                          case "n" :
                                              return charMethod("0110", newValue, inputValue);
                                          case "o" :
                                              return charMethod("0111", newValue, inputValue);
                                          case "p" :
                                              return charMethod("0112", newValue, inputValue);
                                          case "q" :
                                              return charMethod("0113", newValue, inputValue);
                                          case "r" :
                                              return charMethod("0114", newValue, inputValue);
                                          case "s" :
                                              return charMethod("0115", newValue, inputValue);
                                          case "t" :
                                              return charMethod("0116", newValue, inputValue);
                                          case "u" :
                                              return charMethod("0117", newValue, inputValue);
                                          case "v" :
                                              return charMethod("0118", newValue, inputValue);
                                          case "w" :
                                              return charMethod("0119", newValue, inputValue);
                                          case "x" :
                                              return charMethod("0120", newValue, inputValue);
                                          case "y" :
                                              return charMethod("0121", newValue, inputValue);
                                          case "z" :
                                              return charMethod("0122", newValue, inputValue);
                                          case "|" :
                                              return charMethod("124", newValue, inputValue);
                                          default:
                                            window.alert("Maaf char tidak ada/salah");
                                            window.location.reload();
                                            return /* () */0;
                                        }
                                      }));
                        })
                    }), React.createElement("textarea", {
                      className: "form-control",
                      style: {
                        fontSize: "30px",
                        height: "100%",
                        width: "100%",
                        boxSizing: "border-box"
                      },
                      disabled: true,
                      placeholder: "ASCII",
                      value: state[/* outputData */1]
                    }, state[/* outputData */1])));
}

var make = App;

exports.Utils = Utils;
exports.Models = Models;
exports.make = make;
/* doubleQuotesChar Not a pure module */
