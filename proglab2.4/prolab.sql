-- phpMyAdmin SQL Dump
-- version 4.0.4.1
-- http://www.phpmyadmin.net
--
-- Anamakine: 127.0.0.1
-- Üretim Zamanı: 22 May 2017, 14:14:21
-- Sunucu sürümü: 5.5.32
-- PHP Sürümü: 5.4.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Veritabanı: `prolab`
--
CREATE DATABASE IF NOT EXISTS `prolab` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `prolab`;

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `seferler`
--

CREATE TABLE IF NOT EXISTS `seferler` (
  `ukn` int(11) NOT NULL,
  `bn` varchar(45) DEFAULT NULL,
  `bin` varchar(45) DEFAULT NULL,
  `tarih` varchar(45) NOT NULL DEFAULT '',
  `saat` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`tarih`,`ukn`),
  KEY `ukn` (`ukn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `seferler`
--

INSERT INTO `seferler` (`ukn`, `bn`, `bin`, `tarih`, `saat`) VALUES
(111, 'istanbul', 'ankara', '210517', '800'),
(112, 'ankara', 'istanbul', '210517', '900'),
(113, 'izmir', 'malatya', '210517', '1000'),
(114, 'istanbul', 'antalya', '210517', '1100'),
(115, 'antalya', 'edirne', '210517', '1130'),
(116, 'mugla', 'sivas', '210517', '1400'),
(117, 'sinop', 'istanbul', '210517', '1430'),
(118, 'rize', 'konya', '210517', '1400');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `ucaklar`
--

CREATE TABLE IF NOT EXISTS `ucaklar` (
  `ukn` int(11) NOT NULL,
  `umodel` varchar(45) DEFAULT NULL,
  `ukapasite` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`ukn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `ucaklar`
--

INSERT INTO `ucaklar` (`ukn`, `umodel`, `ukapasite`) VALUES
(111, 'boing', '200'),
(112, 'jet', '20'),
(113, 'boing', '150'),
(114, 'boing', '100'),
(115, 'boing', '250'),
(116, 'jet', '25'),
(117, 'boing', '225'),
(118, 'boing', '175');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `yolcu`
--

CREATE TABLE IF NOT EXISTS `yolcu` (
  `tckn` int(11) NOT NULL,
  `isim` varchar(45) DEFAULT NULL,
  `adres` varchar(45) DEFAULT NULL,
  `eposta` varchar(45) DEFAULT NULL,
  `sehir` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`tckn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `yolcu`
--

INSERT INTO `yolcu` (`tckn`, `isim`, `adres`, `eposta`, `sehir`) VALUES
(44, 'gurbuz', 'gebze', 'hhhh', 'malatya'),
(50, 'baris', 'izmit', 'aaaa', 'kocaeli'),
(60, 'fatih', 'yalova', 'bbbb', 'bolu'),
(80, 'baki', 'korfez', 'cccc', 'istanbul'),
(110, 'gurbuz', 'golcuk', 'dddd', 'izmir'),
(199, 'taha', 'derince', 'gggg', 'rize'),
(200, 'baris', 'basiskele', 'eeee', 'ankara'),
(240, 'berk', 'hereke', 'ffff', 'ankara');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `yolcular`
--

CREATE TABLE IF NOT EXISTS `yolcular` (
  `tckn` int(11) NOT NULL,
  `tarih` varchar(45) NOT NULL DEFAULT '',
  `ukn` int(11) NOT NULL DEFAULT '0',
  `bn` varchar(45) NOT NULL DEFAULT '',
  `bin` varchar(45) NOT NULL DEFAULT '',
  PRIMARY KEY (`tckn`,`ukn`,`tarih`,`bn`,`bin`),
  KEY `ukn` (`ukn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `yolcular`
--

INSERT INTO `yolcular` (`tckn`, `tarih`, `ukn`, `bn`, `bin`) VALUES
(50, '210517', 111, 'istanbul', 'ankara'),
(60, '210517', 112, 'ankara', 'istanbul'),
(44, '210517', 113, 'izmir', 'malatya'),
(80, '210517', 113, 'izmir', 'malatya'),
(110, '210517', 114, 'istanbul', 'antalya'),
(200, '210517', 114, 'istanbul', 'antalya'),
(240, '210517', 114, 'istanbul', 'antalya'),
(199, '210517', 115, 'kars', 'nigde');

--
-- Dökümü yapılmış tablolar için kısıtlamalar
--

--
-- Tablo kısıtlamaları `seferler`
--
ALTER TABLE `seferler`
  ADD CONSTRAINT `seferler_ibfk_1` FOREIGN KEY (`ukn`) REFERENCES `ucaklar` (`ukn`) ON DELETE CASCADE;

--
-- Tablo kısıtlamaları `yolcular`
--
ALTER TABLE `yolcular`
  ADD CONSTRAINT `yolcular_ibfk_1` FOREIGN KEY (`ukn`) REFERENCES `ucaklar` (`ukn`) ON DELETE CASCADE,
  ADD CONSTRAINT `yolcular_ibfk_2` FOREIGN KEY (`tckn`) REFERENCES `yolcu` (`tckn`) ON DELETE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
