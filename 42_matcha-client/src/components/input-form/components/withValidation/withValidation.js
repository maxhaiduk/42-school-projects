import React, { Component } from 'react';


const withValidation = (InputField) => {

    return class withValidation extends Component {

        componentDidMount() {
            console.log(this.nv);
        }

        render() {
            return <InputField {...this.props} onInput={() => console.log('hoooc') }/>
        }
    };
};


export default withValidation;
