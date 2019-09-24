type sourceOptions;
[@bs.obj]
external sourceOptions:
    (~uri: string=?, ~method: string=?, ~headers: Js.Dict.t(string)=?,
     ~body: string=?, ~html: string=?, ~baseUrl: string=?)
    => sourceOptions = "";

[@bs.module "react-native-webview"] [@react.component]
external make:
    (   ~source: sourceOptions=?,
        ~onError: (Js.Json.t => unit)=?,
        ~onLoad: (Js.Json.t => unit)=?,
        ~onLoadEnd: (Js.Json.t => unit)=?,
        ~onLoadStart: (Js.Json.t => unit)=?,
        ~onLoadProgress: (Js.Json.t => unit)=?,
        ~onMessage: (Js.Json.t => unit)=?,
        ~onNavigationStateChange: (Js.Json.t => unit)=?,
        ~originWhitelist: array(string)=?,
        ~domStorageEnabled: bool=?,
        ~javaScriptEnabled: bool=?,
        ~androidHardwareAccelerationDisabled: bool=?,
        ~thirdPartyCookiesEnabled: bool=?,
        ~keyboardDisplayRequiresUserAction: bool=?,
        ~allowsBackForwardNavigationGestures: bool=?,
        ~incognito: bool=?,
        ~style: ReactNative.Style.t=?,
        array(unit)
    ) => React.element = "WebView";

let makeProps =
    (~sourceUri=?, ~sourceMethod=?, ~sourceHeaders=?, ~sourceBody=?, ~sourceHtml=?,
     ~sourceBaseUrl=?, ~onError=?, ~onLoad=?, ~onLoadEnd=?, ~onLoadStart=?,
     ~onLoadProgress=?, ~onMessage=?, ~onNavigationStateChange=?,
     ~originWhitelist=?, ~domStorageEnabled=?, ~javaScriptEnabled=?,
     ~androidHardwareAccelerationDisabled=?, ~thirdPartyCookiesEnabled=?,
     ~keyboardDisplayRequiresUserAction=?, ~allowsBackForwardNavigationGestures=?,
     ~incognito=?, ~style=?, ~key=?, ()) =>
    {
        makeProps(
            ~onError?, ~onLoad?, ~onLoadEnd?, ~onLoadStart?, ~onLoadProgress?,
            ~onMessage?, ~onNavigationStateChange?, ~originWhitelist?,
            ~domStorageEnabled?, ~javaScriptEnabled?,
            ~androidHardwareAccelerationDisabled?, ~thirdPartyCookiesEnabled?,
            ~keyboardDisplayRequiresUserAction?, ~allowsBackForwardNavigationGestures?,
            ~incognito?, ~style?, ~key?,
            ~source=sourceOptions(
                ~uri=?sourceUri, ~method=?sourceMethod, ~headers=?sourceHeaders,
                ~body=?sourceBody, ~html=?sourceHtml, ~baseUrl=?sourceBaseUrl
            ),
            ()
        )
    };

[@bs.send] [@bs.scope "ReactNativeWebView"]
external postMessage: (Dom.window, string) => unit = "";
