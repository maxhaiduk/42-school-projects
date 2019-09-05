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

const SignUpForm = () => {

  const classes = useStyles();

  const [formState, setFormState] = useState({
    username: '',
    email: '',
    firstName: '',
    lastName: '',
    password: '',
    confirmPassword: '',
  });

  const {username, email, firstName, lastName, password, confirmPassword} = formState;

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
        label="Username"
        onChange={(event) => {
          handleOnChange(event.target)
        }}
        name="username"
        value={username}
        validators={['required']}
        errorMessages={['this field is required']}
      />
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
        label="First Name"
        onChange={(event) => {
          handleOnChange(event.target)
        }}
        name="firstName"
        value={firstName}
        validators={['required']}
        errorMessages={['this field is required']}
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

export default SignUpForm