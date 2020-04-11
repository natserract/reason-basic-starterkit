
module Utils =  {
    type t_target;

    [@bs.val] external document: Js.t({..}) = "document";
    [@bs.val] [@bs.scope("window")] external alert: string => unit = "alert";

};

module Models = {
    type data_type('a) = ('a);

    type charType =  
      | A
      | B
      | C
      | D
      | E
      | F
      | G
      | H
      | I
      | J
      | K
      | L
      | M
      | N
      | O
      | P
      | Q
      | R
      | S
      | T
      | U
      | V
      | W
      | X
      | Y
      | Z;

    type met = 
      | ENOL;

    type ascii = 
      | NOL_MPAT_LAPAN;

    let ascii_method = 
        fun 
        | NOL_MPAT_LAPAN => "048";
   
};

type t = {
    mutable inputData: Models.data_type(string),
    mutable outputData: Models.data_type(string)
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

        let charMethod = (ascii_code_arg, new_value_arg, form_data_value) =>
            fun 
            | ENOL => {
                Js.Array.push(ascii_code_arg, new_value_arg) |> ignore;
                let getValueProcessing = Js.Array.toString(new_value_arg);
                let valueRegexMatch = Js.String.replaceByRe([%re "/,/gm"], " ", getValueProcessing);

                setState(_ => {
                    inputData: form_data_value,
                    outputData: valueRegexMatch
                }); 
            };
        

        Belt.Array.forEach(changedValue, value => {
            switch (value) {
                | "0" => {    
                    NOL_MPAT_LAPAN
                    -> ascii_method
                    ->  charMethod(newValue, inputValue, ENOL);
                }
                | "1" => {                  
                    Js.Array.push("049", newValue) |> ignore;
                    
                    let getValueProcessing = Js.Array.toString(newValue);
                    let valueRegexMatch = Js.String.replaceByRe([%re "/,/gm"], " ", getValueProcessing);

                    setState(_ => {
                        inputData: inputValue,
                        outputData: valueRegexMatch
                    }); 
                }
                | _ => raise(Not_found)
            };
        });

        Js.log(newValue); 
    };

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
        ())
        ) type_="text" className="form-control" placeholder="Char" value=(state.inputData) onChange=(event => handleChange(event))>

        </textarea>
        
        <textarea style=(
            ReactDOMRe.Style.make(
                ~width="100%",
                ~height="100%",
                ~boxSizing="border-box",
        ())
        ) disabled=(true) value=(state.outputData) className="form-control" placeholder="ASCII">
            (state.outputData -> React.string)
        </textarea>
    </form>
};