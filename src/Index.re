module TestComp = {
  let component = ReasonReact.statelessComponent("Page");

  let make = _children => {
    ...component,
    render: _self => {
      let input = <input type_="text" name="foo" />;

      let working =
        ReasonReact.cloneElement(input, ~props={"autofocus": ""}, [||]);

      let notWorking =
        ReasonReact.cloneElement(input, ~props={"autoFocus": ""}, [||]);

      <div> notWorking </div>;
    },
  };
};

ReactDOMRe.renderToElementWithId(<TestComp />, "index1");