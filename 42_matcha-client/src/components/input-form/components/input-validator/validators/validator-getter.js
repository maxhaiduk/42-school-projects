import RequiredValidator from './required-validator';
import LengthValidator from './length-validator';
import EqualValidator from './equal-validator';

const validators = {
    RequiredValidator,
    LengthValidator,
    EqualValidator,
};

const getDynamicValidator = (validatorName) => {

    const validator = validators[validatorName];

    if (!validator) {
        throw new Error(`${validatorName} doesn't exists`);
    }

    return validator;
};

export default getDynamicValidator;