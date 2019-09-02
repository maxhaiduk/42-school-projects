import React from 'react'
import { CurrentThemeConsumer } from "../../context/current-theme-context";

const ThemeSwitcher = function() {

  return (
    <CurrentThemeConsumer>
      {
        ({currentTheme, changeCurrentTheme}) => (
          <button
            onClick={ () => {
              console.log(currentTheme);}}>
            Change THEME
          </button>

        )}

    </CurrentThemeConsumer>
  )
};

export default ThemeSwitcher;