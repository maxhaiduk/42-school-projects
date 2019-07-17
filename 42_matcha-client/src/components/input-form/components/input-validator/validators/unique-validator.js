import AbstractValidator from './abstract-validator';


export default class UniqueValidator extends AbstractValidator {

    async validate(value, uniqueHandler) {

        const valid = await uniqueHandler(this.inputName, value);

        console.log('result from service: ', valid);

        return {
            valid,
            errorMessage: this.getErrorMessage(valid, value),
        }
    }

    getErrorMessage(valid, value) {
        return `The ${this.inputName} '${value}' is ` +
            `${valid ? 'is available' : 'already taken'}`;
    }
}