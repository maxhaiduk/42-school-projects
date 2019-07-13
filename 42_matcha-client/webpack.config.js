const webpack = require('webpack');
const path = require('path');

module.exports = {
    mode: 'development',
    entry: './src/index.js',
    output: {
        filename: 'bundle.js',
        path: path.resolve(__dirname, 'dist')
    },
    devtool: 'inline-source-map',
    devServer: {
        contentBase: path.join(__dirname, 'dist'),
        port: 3000,
    },
    module: {
        rules: [
            {
                test: /\.jsx?$/,
                exclude: /node_modules/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: [
                            '@babel/preset-env',
                            '@babel/preset-react'
                        ],
                        'plugins': [
                            [
                                'babel-plugin-root-import', {
                                    'rootPathSuffix': 'src'
                                }
                            ]
                        ]
                    }
                }
            },
            {
                test: /\.p?css$/,
                exclude: /node_modules/,
                use: [
                    {
                        loader: 'style-loader',
                    },
                    {
                        loader: 'css-loader',
                    },
                    {
                        loader: 'postcss-loader',
                        ident: 'postcss',
                        options: {
                            importLoaders: 1,
                            plugins: [
                                require('precss'),
                                require('tailwindcss'),
                            ]
                        }
                    }
                ]
            },
        ]
    },
};