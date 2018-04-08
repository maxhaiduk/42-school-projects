-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Апр 08 2018 г., 11:27
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
(9, 'm', '05ee70f67fed50f8c5ac896c552b8b6b596a9353e67ae60a74bc112f3c7a5ee6131fd4a164479b263cc8916714d94d8b5026e7856eb5752031ff2c549343e505'),
(10, 'maks', '05ee70f67fed50f8c5ac896c552b8b6b596a9353e67ae60a74bc112f3c7a5ee6131fd4a164479b263cc8916714d94d8b5026e7856eb5752031ff2c549343e505');

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
  MODIFY `user_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
