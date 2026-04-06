import React, { useContext } from 'react'
import CurrentThemeContext from "../../context/current-theme-context";

import {
  makeStyles,
  FormControl,
  InputLabel,
  Select,
  MenuItem
} from "@material-ui/core";

const useStyles = makeStyles(theme => ({
  root: {
    display: 'flex',
    flexWrap: 'wrap',
  },
  formControl: {
    margin: theme.spacing(1),
    minWidth: 80,
  },
}));

const ThemeSwitcher = () => {

  const {currentTheme, changeTheme} = useContext(CurrentThemeContext);
  const classes = useStyles();

  return (

    <FormControl className={classes.formControl}>
      <InputLabel htmlFor='theme-switcher'>Theme</InputLabel>
      <Select
        value={currentTheme}
        onChange={(event) => {
          changeTheme(event.target.value)
        }}
        inputProps={{
          name: 'Theme',
          id: 'theme-switcher',
        }}
      >
        <MenuItem value='light'>light</MenuItem>
        <MenuItem value='dark'>dark</MenuItem>
      </Select>
    </FormControl>
  )
};

export default ThemeSwitcher;