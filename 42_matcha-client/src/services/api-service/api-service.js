import { StringHelper } from '~/helpers';


export default class ApiService {

    state = {
        names: [
            'maks',
            'john',
        ]
    };

    async isLoginAvailable(login) {
        return new Promise(resolve => {
            setTimeout(() => {
                resolve(!this.state.names.includes(login));
            }, 1000)
        })
    }

    checkAvailability = async (inputName, value) => {
        let methodName = `is${StringHelper.capitalize(inputName)}Available`;

        if (this[methodName] === undefined) {
            throw new Error(`Method ${methodName} was not found in ` +
                this.constructor.name);
        }

        return await (this[methodName])(value);
    }
}
