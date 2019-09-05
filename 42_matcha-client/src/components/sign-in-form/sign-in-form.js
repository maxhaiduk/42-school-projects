import React, { useState } from 'react';
import { ValidatorForm, TextValidator } from 'react-material-ui-form-validator';
import { Button, makeStyles } from "@material-ui/core";

const useStyles = makeStyles(() => ({
  container: {
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center',
  },
  textField: {
    marginTop: 20,
    width: '100%',
  },

  button: {
    marginTop: 20,
  }
}));

const SignInForm = () => {

  const classes = useStyles();

  const [formState, setFormState] = useState({
    email: '',
    password: '',
  });

  const {email, password} = formState;

  const handleOnChange = ({name, value}) => {
    setFormState({
      ...formState,
      [name]: value,
    })
  };

  return (
    <ValidatorForm
      className={classes.container}
      onSubmit={() => {
        console.log(formState)
      }}
      onError={errors => console.log(errors)}
    >
      <TextValidator
        className={classes.textField}
        label="Email"
        onChange={(event) => {
          handleOnChange(event.target)
        }}
        name="email"
        value={email}
        validators={['required', 'isEmail']}
        errorMessages={['this field is required', 'email is not valid']}
      />
      <TextValidator
        className={classes.textField}
        label="Password"
        onChange={(event) => {
          handleOnChange(event.target)
        }}
        name="password"
        value={password}
        validators={['required']}
        errorMessages={['this field is required']}
      />
      <Button className={classes.button} type="submit" variant="contained"
              color="primary">
        Submit
      </Button>
    </ValidatorForm>
  );
};

export default SignInForm