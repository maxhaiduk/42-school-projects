import React from 'react';
import { BrowserRouter, Route, Switch } from "react-router-dom";

import LoginPage from '../pages/login-page';

const App = () => {

  return (
      <BrowserRouter>
          <React.StrictMode>
              <Switch>
                  <Route path="/login" component={LoginPage} />
              </Switch>
          </React.StrictMode>
      </BrowserRouter>
  );
};

export default App;
