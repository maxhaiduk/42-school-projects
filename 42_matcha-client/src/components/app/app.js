import React from 'react';
import { BrowserRouter, Route, Switch } from "react-router-dom";
import { SignInPage, SignUpPage } from '../pages';
import withMuiTheme from '../../mui-theme';
import Header from '../header';

import ThemeSwitcher from '../theme-switcher/theme-switcher';

const App = () => {

  return (
    <BrowserRouter>
      <React.StrictMode>
        <div>
          <ThemeSwitcher/>
          <Header/>
          <Switch>
            <Route path="/sign-in" component={SignInPage}/>
            <Route path='/sign-up' component={SignUpPage}/>
          </Switch>
        </div>
      </React.StrictMode>
    </BrowserRouter>
  );
};

export default withMuiTheme(App);
