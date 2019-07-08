import RequiredValidator from './required-validator';
import LengthValidator from './length-validator';

const validators = {
  RequiredValidator,
    LengthValidator,
};

const getDynamicValidator = (validatorName) => {

    const validator = validators[validatorName];

    if (!validator) {
        throw new Error(`Validator ${validatorName} doesn't exists`);
    }

    return validator;
};

export default getDynamicValidator;