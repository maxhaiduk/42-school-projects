import React from "react";


const CurrentThemeContext = React.createContext({
  currentTheme: '',
  changeTheme: () => {},
});


export default CurrentThemeContext;
