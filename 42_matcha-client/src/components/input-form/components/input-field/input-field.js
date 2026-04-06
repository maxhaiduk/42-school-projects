import React from 'react';
import { StringHelper } from '~/helpers';
import Spinner from '~/components/spinner';
import { TextField } from "@material-ui/core";

const InputField = (props) => {

  const {type, id, name, valid, message, loading, className} = props;
  let {label = StringHelper.toHumanCaseCap(name)} = props;
  const required = (props.rules || []).includes('required');
  label = required ? label + ' *' : label;

  const inputId = id + '-input';

  return (
    <div id={id} className={'input-field-container ' + className}>
      <div className='input-container'>
        <TextField
          id={inputId}
          className={ className }
          error={valid != null && !valid}
          type={type}
          name={name}
          label={label}
          helperText={message}
          disabled={loading}
          onChange={(event) => {
            props.onInput(props.name, event.target.value)
          }}
        />
        {loading ? <Spinner width={25} thickness={15}/> : null}
      </div>
    </div>
  )
};

export default InputField;
