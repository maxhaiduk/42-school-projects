import React from "react";


const {
  Provider: CurrentThemeProvider,
  Consumer: CurrentThemeConsumer,
} = React.createContext({
  currentTheme: 'light',
  changeCurrentTheme: () => {},
});


export {
  CurrentThemeProvider,
  CurrentThemeConsumer,
}