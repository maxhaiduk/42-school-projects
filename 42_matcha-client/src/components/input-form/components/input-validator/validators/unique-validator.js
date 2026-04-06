import AbstractValidator from './abstract-validator';


export default class UniqueValidator extends AbstractValidator {

    async validate(value, uniqueHandler) {

        const valid = await uniqueHandler(this.inputName, value);

        return {
            valid,
            message: this.getMessage(valid, value),
        }
    }

    getMessage(valid, value) {
        return `The ${this.inputName} '${value}' is ` +
            `${valid ? 'is available' : 'already taken'}`;
    }
}