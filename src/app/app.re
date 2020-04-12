
module Utils =  {
    type t;
    [@bs.val] external document: Js.t({..}) = "document";
    [@bs.val] [@bs.scope("window")] external alert: string => unit = "alert";
    [@bs.val] [@bs.scope("window", "location")] external forceReload: unit => unit = "reload";
};

module Models = {
    type generic('a) = ('a);

    type state = {
        mutable inputData: generic(string),
        mutable outputData: generic(string)
    };

    // we use regex because reason give a following error!
    let doubleQuotesChar = [%re "/\"*/g"]; // Can't use this

    type met_t = 
      | ASCII_00
      | ASCII_01
      | ASCII_02
      | ASCII_03
      | ASCII_04
      | ASCII_05
      | ASCII_06
      | ASCII_07
      | ASCII_08
      | ASCII_09
      | ASCII_A
      | ASCII_B
      | ASCII_C
      | ASCII_D
      | ASCII_E
      | ASCII_F
      | ASCII_G
      | ASCII_H
      | ASCII_I
      | ASCII_J
      | ASCII_K
      | ASCII_L
      | ASCII_M
      | ASCII_N
      | ASCII_O
      | ASCII_P
      | ASCII_Q
      | ASCII_R
      | ASCII_S
      | ASCII_T
      | ASCII_U
      | ASCII_V
      | ASCII_W
      | ASCII_X
      | ASCII_Y
      | ASCII_Z
      | ASCII_a
      | ASCII_b
      | ASCII_c
      | ASCII_d
      | ASCII_e
      | ASCII_f
      | ASCII_g
      | ASCII_h
      | ASCII_i
      | ASCII_j
      | ASCII_k
      | ASCII_l
      | ASCII_m
      | ASCII_n
      | ASCII_o
      | ASCII_p
      | ASCII_q
      | ASCII_r
      | ASCII_s
      | ASCII_t
      | ASCII_u
      | ASCII_v
      | ASCII_w
      | ASCII_x
      | ASCII_y
      | ASCII_z
      | ASCII_BACKSPACE
      | ASCII_KOMA
      | ASCII_TANDA_SERU
      | ASCII_DOBLE_QOTES
      | ASCII_HASTAG
      | ASCII_DOLAR
      | ASCII_PERSEN
      | ASCII_DAN
      | ASCII_SINGGEL_QUOTE
      | ASCII_KURUNG_AWAL
      | ASCII_KURUNG_AKHIR
      | ASCII_BINTANG
      | ASCII_TAMBAH
      | ASCII_KURANG
      | ASCII_TITIK
      | ASCII_SLASH
      | ASCII_SEMICOLON
      | ASCII_TITIKDUA
      | ASCII_UNDERSCORE
      | ASCII_VERTICAL_BAR
      | ASCII_SAMADENGAN
      | ASCII_AT;

    let ascii_method = 
        fun 
        | ASCII_00 => "048"
        | ASCII_01 => "049"
        | ASCII_02 => "050"
        | ASCII_03 => "051"
        | ASCII_04 => "052"
        | ASCII_05 => "053"
        | ASCII_06 => "054"
        | ASCII_07 => "055"
        | ASCII_08 => "056"
        | ASCII_09 => "057"
        | ASCII_A => "065"
        | ASCII_B => "066"
        | ASCII_C => "067"
        | ASCII_D => "068"
        | ASCII_E => "069"
        | ASCII_F => "070"
        | ASCII_G => "071"
        | ASCII_H => "072"
        | ASCII_I => "073"
        | ASCII_J => "074"
        | ASCII_K => "075"
        | ASCII_L => "076"
        | ASCII_M => "077"
        | ASCII_N => "078"
        | ASCII_O => "079"
        | ASCII_P => "080"
        | ASCII_Q => "081"
        | ASCII_R => "082"
        | ASCII_S => "083"
        | ASCII_T => "084"
        | ASCII_U => "085"
        | ASCII_V => "086"
        | ASCII_W => "087"
        | ASCII_X => "088"
        | ASCII_Y => "089"
        | ASCII_Z => "090"
        | ASCII_a => "097"
        | ASCII_b => "098"
        | ASCII_c => "099"
        | ASCII_d => "0100"
        | ASCII_e => "0101"
        | ASCII_f => "0102"
        | ASCII_g => "0103"
        | ASCII_h => "0104"
        | ASCII_i => "0105"
        | ASCII_j => "0106"
        | ASCII_k => "0107"
        | ASCII_l => "0108"
        | ASCII_m => "0109"
        | ASCII_n => "0110"
        | ASCII_o => "0111"
        | ASCII_p => "0112"
        | ASCII_q => "0113"
        | ASCII_r => "0114"
        | ASCII_s => "0115"
        | ASCII_t => "0116"
        | ASCII_u => "0117"
        | ASCII_v => "0118"
        | ASCII_w => "0119"
        | ASCII_x => "0120"
        | ASCII_y => "0121"
        | ASCII_z => "0122"
        | ASCII_BACKSPACE => "032"
        | ASCII_KOMA => "044"
        | ASCII_TANDA_SERU => "033"
        | ASCII_DOBLE_QOTES => "034"
        | ASCII_HASTAG => "035"
        | ASCII_DOLAR => "036"
        | ASCII_PERSEN => "037"
        | ASCII_DAN => "038"
        | ASCII_SINGGEL_QUOTE => "039"
        | ASCII_KURUNG_AWAL => "040"
        | ASCII_KURUNG_AKHIR => "041"
        | ASCII_BINTANG => "042"
        | ASCII_TAMBAH => "043"
        | ASCII_KURANG => "045"
        | ASCII_TITIK => "046"
        | ASCII_SLASH => "047"
        | ASCII_TITIKDUA => "058"
        | ASCII_SEMICOLON => "059"
        | ASCII_UNDERSCORE => "095" 
        | ASCII_VERTICAL_BAR => "124"
        | ASCII_SAMADENGAN => "061"
        | ASCII_AT => "064"
        | _ => ""
};


[@react.component]
let make = () => {
    open Models;

    let (state, setState) = React.useState(() => {
        inputData: "",
        outputData: ""
    });

    let handleChange = (event) => {
        event -> ReactEvent.Form.persist;
        let inputValue = event -> ReactEvent.Form.target##value;
        let newValue = [||];
        
        let changedValue = Js.String.split("", inputValue);
        let _lastIndex = Js.Array.length(changedValue) - 1;
    
        let charMethod = (ascii_code_arg, new_value_arg, form_data_value) => {
            Js.Array.push(ascii_code_arg, new_value_arg) |> ignore;
            let getValueProcessing = Js.Array.toString(new_value_arg);
            let valueRegexMatch = Js.String.replaceByRe([%re "/,/gm"], " ", getValueProcessing);

            setState(_ => {
                inputData: form_data_value,
                outputData: valueRegexMatch
            }); 
        }

        Belt.Array.forEach(changedValue, value => {
            switch (value) {
                | "0" => {    
                    ASCII_00
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "1" => {    
                    ASCII_01
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "2" => {    
                    ASCII_02
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "3" => {    
                    ASCII_03
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "4" => {    
                    ASCII_04
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "5" => {    
                    ASCII_05
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "6" => {    
                    ASCII_06
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "7" => {    
                    ASCII_07
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "8" => {    
                    ASCII_08
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "9" => {    
                    ASCII_09
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "A" => {    
                    ASCII_A
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "B" => {    
                    ASCII_B
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "C" => {    
                    ASCII_C
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "D" => {    
                    ASCII_D
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "E" => {    
                    ASCII_E
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "F" => {    
                    ASCII_F
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "G" => {    
                    ASCII_G
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "H" => {    
                    ASCII_H
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "I" => {    
                    ASCII_I
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "J" => {    
                    ASCII_J
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "K" => {    
                    ASCII_K
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "L" => {    
                    ASCII_L
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "M" => {    
                    ASCII_M
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "N" => {    
                    ASCII_N
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "O" => {    
                    ASCII_O
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "P" => {    
                    ASCII_P
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "Q" => {    
                    ASCII_Q
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "R" => {    
                    ASCII_R
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "S" => {    
                    ASCII_S
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "T" => {    
                    ASCII_T
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "U" => {    
                    ASCII_U
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "V" => {    
                    ASCII_V
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "W" => {    
                    ASCII_W
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "X" => {    
                    ASCII_X
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "Y" => {    
                    ASCII_Y
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "Z" => {    
                    ASCII_Z
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "a" => {    
                    ASCII_a
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "b" => {    
                    ASCII_b
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "c" => {    
                    ASCII_c
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "d" => {    
                    ASCII_d
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "e" => {    
                    ASCII_e
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "f" => {    
                    ASCII_f
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "g" => {    
                    ASCII_g
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "h" => {    
                    ASCII_h
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "i" => {    
                    ASCII_i
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "j" => {    
                    ASCII_j
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "k" => {    
                    ASCII_k
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "l" => {    
                    ASCII_l
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "m" => {    
                    ASCII_m
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "n" => {    
                    ASCII_n
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "o" => {    
                    ASCII_o
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "p" => {    
                    ASCII_p
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "q" => {    
                    ASCII_q
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "r" => {    
                    ASCII_r
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "s" => {    
                    ASCII_s
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "t" => {    
                    ASCII_t
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "u" => {    
                    ASCII_u
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "v" => {    
                    ASCII_v
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "w" => {    
                    ASCII_w
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "x" => {    
                    ASCII_x
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "y" => {    
                    ASCII_y
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "z" => {    
                    ASCII_z
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | " " => {    
                    ASCII_BACKSPACE
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "," => {    
                    ASCII_KOMA
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "!" => {    
                    ASCII_TANDA_SERU
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                
                | "#" => {    
                    ASCII_HASTAG
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "$" => {    
                    ASCII_DOLAR
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "%" => {    
                    ASCII_PERSEN
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "&" => {    
                    ASCII_DAN
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | ";" => {    
                    ASCII_SEMICOLON
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "/" => {    
                    ASCII_SLASH
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "." => {    
                    ASCII_TITIK
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "+" => {    
                    ASCII_TAMBAH
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "-" => {    
                    ASCII_KURANG
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "*" => {    
                    ASCII_BINTANG
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "(" => {    
                    ASCII_KURUNG_AWAL
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | ")" => {    
                    ASCII_KURUNG_AKHIR
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | ":" => {    
                    ASCII_TITIKDUA
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "_" => {    
                    ASCII_UNDERSCORE
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "|" => {    
                    ASCII_VERTICAL_BAR
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "'" => {    
                    ASCII_SINGGEL_QUOTE
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "=" => {    
                    ASCII_SAMADENGAN
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | "@" => {    
                    ASCII_AT
                    ->  ascii_method
                    ->  charMethod(newValue, inputValue);
                }
                | _ => {
                    "Maaf char tidak ada/salah" -> Utils.alert;
                    Utils.forceReload()
                }
            };
        });
    };

    <main>
        <h1 style=(ReactDOMRe.Style.make(
            ~textAlign="center",
            ~padding="30px",
            ~fontFamily = "sans-serif",
        ()))>"ASCII GENERATOR" -> React.string</h1>
        <form style=(
            ReactDOMRe.Style.make(
                ~display="flex",
                ~alignItems="center",
                ~justifyContent = "center",
                ~height="100vh",
            ())
        )>
            <textarea style=(
                ReactDOMRe.Style.make(
                    ~width="100%",
                    ~height="100%",
                    ~boxSizing="border-box",
                    ~fontSize="30px",
            ())) 
                className="form-control" 
                placeholder="Char" 
                value=(state.inputData) 
                onChange=(event => handleChange(event))>
            </textarea>
            
            <textarea style=(
                ReactDOMRe.Style.make(
                    ~width="100%",
                    ~height="100%",
                    ~boxSizing="border-box",
                    ~fontSize="30px",
                ())) 
                disabled=(true) 
                value=(state.outputData) 
                className="form-control" 
                placeholder="ASCII">
                
                (state.outputData -> React.string)
            </textarea>
        </form>
    </main>
};