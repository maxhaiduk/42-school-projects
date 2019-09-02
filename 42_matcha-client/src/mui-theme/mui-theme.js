import React from 'react'
import { useState } from 'react';
import { green, red } from '@material-ui/core/colors';
import { MuiThemeProvider, createMuiTheme } from '@material-ui/core/styles';
import CssBaseline from '@material-ui/core/CssBaseline';

import { CurrentThemeProvider } from '../context/current-theme-context'

console.log(CurrentThemeProvider);

const darkTheme = createMuiTheme({
  palette: {
    type: 'dark',
    primary: red,
    secondary: green,
  },
  status: {
    danger: 'orange',
  },
});

const lightTheme = createMuiTheme({
  palette: {
    type: 'light',
    primary: red,
    secondary: green,
  },
  status: {
    danger: 'orange',
  },
});


function withMuiTheme(Component) {
  function withMuiTheme(props) {

    // const [ currentTheme, changeCurrentTheme ] = useState('light');

    const [ count, setCount ] = useState(0);


    return (
      <CurrentThemeProvider value={{count, setCount}}>
        <MuiThemeProvider theme={lightTheme}>
          <CssBaseline/>
          <Component {...props} />
        </MuiThemeProvider>
      </CurrentThemeProvider>
    );
  }

  return withMuiTheme;
}

export default withMuiTheme;