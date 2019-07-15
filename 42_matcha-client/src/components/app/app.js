import React from 'react';
import { BrowserRouter, Route, Switch } from "react-router-dom";

import SignInPage from '../pages/sign-in-page';
import SignUpPage from "../pages/sign-up-page/sign-up-page";

const App = () => {

  return (
      <BrowserRouter>
          <React.StrictMode>
              <Switch>
                  <Route path="/sign-in" component={ SignInPage } />
                  <Route path='/sign-up' component={ SignUpPage } />
              </Switch>
          </React.StrictMode>
      </BrowserRouter>
  );
};

export default App;
