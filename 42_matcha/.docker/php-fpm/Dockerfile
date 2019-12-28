FROM php:7.4-fpm

# xdebug
RUN pecl install xdebug-2.9.0 && docker-php-ext-enable xdebug
COPY config/xdebug.ini $PHP_INI_DIR/conf.d/

# composer
COPY composer-installer.sh /usr/local/bin/
RUN /usr/local/bin/composer-installer.sh\
 && mv composer.phar /usr/local/bin/composer\
 && chmod +x /usr/local/bin/composer\
 && composer --version
