
module Utils =  {
    type t;
    [@bs.val] external document: Js.t({..}) = "document";
    [@bs.val] [@bs.scope("window")] external alert: string => unit = "alert";
    [@bs.val] [@bs.scope("window", "location")] external forceReload: unit => unit = "reload";
};


[@react.component]
let make = () => {
    <main>
        <h1 style=(ReactDOMRe.Style.make(
            ~textAlign="center",
            ~padding="30px",
            ~fontFamily = "sans-serif",
        ()))>"ReasonReact Basic Starter Kit" -> React.string</h1>
    </main>
};