open Jest;
open Expect;

test("the works", () => {
    let style = ReactNative.Style.style(~margin=ReactNative.Style.auto, ());
    let sourceUri = "http://www.ebay.com/";
    let sourceMethod = "POST";
    let sourceHeaders = [|("X-Hello", "hi")|] |> Js.Dict.fromArray;
    let sourceBody = "{}";
    let onError = _ => Js.log("onError");
    let onLoad = _ => Js.log("onLoad");
    let onLoadEnd = _ => Js.log("onLoadEnd");
    let onLoadStart = _ => Js.log("onLoadStart");
    let onLoadProgress = _ => Js.log("onLoadProgress");
    let onMessage = _ => Js.log("onMessage");
    let onNavigationStateChange = _ => Js.log("onNavigationStateChange");
    let originWhitelist = [|"*"|];
    let domStorageEnabled = false;
    let javaScriptEnabled = true;
    let androidHardwareAccelerationDisabled = false;
    let thirdPartyCookiesEnabled = true;
    let keyboardDisplayRequiresUserAction = false;
    let allowsBackForwardNavigationGestures = true;
    let incognito = false;

   <ReactNativeWebView
        style sourceUri sourceMethod sourceHeaders sourceBody
        onError onLoad onLoadEnd onLoadStart onLoadProgress onMessage
        onNavigationStateChange originWhitelist domStorageEnabled javaScriptEnabled
        androidHardwareAccelerationDisabled thirdPartyCookiesEnabled
        keyboardDisplayRequiresUserAction allowsBackForwardNavigationGestures
        incognito />
    |> ReactTestRenderer.create
    |> ReactTestRenderer.toJSON
    |> expect
    |> toMatchSnapshot;
});

test("html", () => {
    let sourceHtml = "<b>yo</b>";
    let sourceBaseUrl = "http://whitehouse.gov";

   <ReactNativeWebView sourceHtml sourceBaseUrl />
    |> ReactTestRenderer.create
    |> ReactTestRenderer.toJSON
    |> expect
    |> toMatchSnapshot;
});
