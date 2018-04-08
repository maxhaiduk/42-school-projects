-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Апр 08 2018 г., 06:05
-- Версия сервера: 5.7.21
-- Версия PHP: 7.1.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `music_shop`
--

-- --------------------------------------------------------

--
-- Структура таблицы `products`
--

CREATE TABLE `products` (
  `id` int(11) NOT NULL,
  `category` varchar(100) NOT NULL,
  `name` varchar(50) NOT NULL,
  `price` int(11) NOT NULL,
  `image` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `products`
--

INSERT INTO `products` (`id`, `category`, `name`, `price`, `image`) VALUES
(1, 'drums', 'TAMA Iron Cobra', 1100, 'img000.png'),
(2, 'drums', 'Yamaha RXS-760', 900, 'img001.png'),
(3, 'drums', 'Ludvig Carl17', 800, 'img002.jpg'),
(4, 'eguitars', 'Gibson SG Standart', 800, 'SGSHCCH1-Finish-Shot3.jpg'),
(5, 'eguitars', 'Epiphone 1967 Flying V', 650, 'epiphone-1967-flying-v-22325.jpg'),
(6, 'eguitars', 'CORT CR250', 500, 'CORT_CR250.png'),
(7, 'aguitars', 'Yamaha F320', 300, 'lg_F325.jpg'),
(8, 'aguitars', 'Fender MC-1', 480, 'fenderMC1.jpg'),
(9, 'aguitars', 'Luna Oasis Left Handed', 630, 'luna-henna-oasis.jpg'),
(10, 'aguitars', 'Veillette', 500, 'veillette.jpg'),
(11, 'synt', 'Casio CTK-6000', 450, 'casio-CTK-6000.jpg'),
(12, 'synt', 'Yamaha MOX8', 500, 'yamaha-MOX8.jpg'),
(13, 'synt', 'Yamaha Motif XF7', 580, 'yamaha-motif-xf7.jpg'),
(14, 'sax', 'Antoin Sonnet T1', 750, 'antoin-sonnet-t1.jpg'),
(15, 'sax', 'Selmer Paris 54', 950, 'selmer-paris-54.jpg'),
(16, 'sax', 'Soprillo 117', 920, 'soprillo.jpg');

-- --------------------------------------------------------

--
-- Структура таблицы `users`
--

CREATE TABLE `users` (
  `user_id` int(11) NOT NULL,
  `login` varchar(32) NOT NULL,
  `password` varchar(1000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `users`
--

INSERT INTO `users` (`user_id`, `login`, `password`) VALUES
(1, 'admin ', '0930b2ef44bc6bc67580370d7b46dca464b14ed14e9bfe41591b6ac1829e2b2b647c8b11c86723c3677e5d1870dfa9ef53eb3dfb71e33c0b6a67a2ac0bad17be'),
(2, 'maks', 'eaa18fa9caa3aed6bd5784c8bf8f052035e0883bbdb3f0ace470920d543aedb61a016e1422d39d20584aebdad97c163756d1871a2cc715410b23f89c01c14ed9'),
(3, 'Vasiliy', '5535c43af740695237ba53f9d98e231cea230de2d0996243b485464d2a4eed859985e448a5cf0d03bfe8ee3d083c9533e39e55a33d777e71257de99b31084682'),
(4, 'x', '086794cfbe18b122c757ee481c4166d814b650e9d150920beb3f0e75a26df01be3ebe35cb879b237ad0dd263dfcb83cc6223755ea1e7cded7de8dfc139d55bbf'),
(5, 'qqq', '35509ff41cdae164373beb51c680090200435f7a8480d856ca23ca2920d6e851b571b9397275cd393e7efb5671c062367856295b60f3c3285b14cf65ad3c28f5'),
(6, 'q', '8513c69d070a008df008aef8624ed24afc81b170d242faf5fafe853d4fe9bf8aa7badfb0fd045d7b350b19fbf8ef6b2a51f17a07a1f6819abc9ba5ce43324244'),
(7, 'dasha', '5535c43af740695237ba53f9d98e231cea230de2d0996243b485464d2a4eed859985e448a5cf0d03bfe8ee3d083c9533e39e55a33d777e71257de99b31084682');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`user_id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `products`
--
ALTER TABLE `products`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT для таблицы `users`
--
ALTER TABLE `users`
  MODIFY `user_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
