-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 04, 2020 at 03:56 PM
-- Server version: 10.4.16-MariaDB
-- PHP Version: 7.4.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dbsos`
--

--
-- Dumping data for table `instructions`
--

INSERT INTO `instructions` (`RecipeId`, `Steps`, `Descriptions`) VALUES
('1000', '1', 'Perap ayam dengan garam kunyit. Goreng sehingga masak. Angkat dan ketepikan.'),
('1000', '2', 'Panaskan minyak dan tumis bahan kisar hingga masak.'),
('1000', '3', 'Masukkan cili kisar. Tumis hingga cili masak.'),
('1000', '4', 'Masukkan gula, garam, sos cili, sos tomato dan sedikit air. Kacau rata.'),
('1000', '5', 'Masukkan bawang hiris. kacau sehingga bawang separuh layu.'),
('1000', '6', 'Masukkan ayam goreng. Kacau sebati. Angkat dan hidang.'),
('1001', '1', 'Panaskan minyak. Tumis bahan hiris sehingga naik bau.'),
('1001', '2', 'Masukkan daun kari. Tumis sekejap.'),
('1001', '4', 'Masukkan ayam, tomato dan kentang ke dalam periuk.'),
('1001', '5', 'Masukkan sos tiram dan kicap. Kacau dan masukkan garam.'),
('1001', '6', 'Masukkan air dan bancuhan tepung jagung.'),
('1001', '7', 'Kacau sehingga ayam masak dan hidang bersama taburan daun bawang.'),
('1002', '1', 'Panaskan minyak. Goreng kentang sehingga empuk. Angkat dan ketepikan.'),
('1003', '1', 'Panaskan minyak. Tumis bahan kisar hingga naik bau.'),
('1003', '2', 'Masukkan air dan ubi kentang. Masak seketika sebelum masukkan carrot.'),
('1003', '3', 'Masak sehingga kentang empuk.'),
('1003', '4', 'Masukkan ayam dan rempah sup. Setelah ayam hampir masak, masukkan saderi.'),
('1003', '5', 'Masukkan garam dan daun sup. Angkat dan taburkan bawang goreng sebelum dihidangkan.'),
('1004', '1', 'Goreng ayam yang telah diperap dengan garam kunyit sehingga masak.'),
('1004', '2', 'Angkat dan ketepikan. Tumbuk bawang dan cili padi. Tumis sehingga naik bau.'),
('1004', '3', 'Masukkan tomato dan garam. Masak seketika. Masukkan ayam yang telah digoreng.'),
('1004', '4', 'Kacau rata. Angkat dan hidangkan.'),
('1005', '1', 'Tumis bahan kisar sehingga naik bau. Masukkan daun kari. Tumis sekejap.'),
('1005', '2', 'Masukkan serbuk kari dan serbuk lada yang telah dibancuh dengan air.'),
('1005', '3', 'Tumis sehingga masak. Masukkan ayam, kentang, tomato, garam dan air secukupnya.'),
('1005', '4', 'Masak dengan api serdehana sehingga masak. Angkat dan hidang.');

--
-- Dumping data for table `recipe`
--

INSERT INTO `recipe` (`RecipeId`, `RecipeName`) VALUES
('', ''),
('1000', 'Ayam Sambal'),
('1001', 'Ayam Halia'),
('1002', 'Ayam Kicap'),
('1003', 'Ayam Sup'),
('1004', 'Ayam Berlada'),
('1005', 'Ayam Kari');

--
-- Dumping data for table `recipeingredients`
--

INSERT INTO `recipeingredients` (`RecipeId`, `IngredientName`, `Amount`) VALUES
('1000', 'ayam - potong kecil', '1/2 ekor'),
('1000', 'cili kisar', '3 sudu bes'),
('1000', 'garam', '1 sudu kec'),
('1000', 'gula', '1 sudu bes'),
('1000', 'sos cili', '2 sudu bes'),
('1000', 'sos tomato', '2 sudu bes'),
('1000', 'bawang holland(hiris', '1/2 biji'),
('1000', 'bawang besar(kisar)', '1 1/2 biji'),
('1000', 'bawang putih(kisar)', '4 ulas'),
('1001', 'ayam', '500g'),
('1001', 'bawang putih-hiris', '4 ulas'),
('1001', 'halia-hiris', '2cm'),
('1001', 'kicap cair', '1 sudu besar'),
('1001', 'sos tiram', '1 sudu besar'),
('1001', 'bawang besar-hiris', '1 biji'),
('1001', 'cili merah-hiris', '1 biji'),
('1001', 'daun bawang-hiris', '1 tangkai'),
('1001', 'tepung jagung', '1 sudu kecil'),
('1001', 'garam', '1/2 sudu kecil'),
('1001', 'daun kari', '2 tangkai'),
('1001', 'tomato-belah 4', '1 biji'),
('1001', 'kentang-belah 4', '1 biji'),
('1002', 'ayam', '6-7 ketul'),
('1002', 'kicap lemak manis', 'secukup rasa'),
('1002', 'bawang holland-belah', '1/2 biji'),
('1002', 'cili padi', '3-4 tangkai'),
('1002', 'bawang merah-kisar', '3 biji'),
('1002', 'bawang putih-kisar', '2 ulas'),
('1002', 'tomato-belah 4', '1 biji'),
('1002', 'kentang-hiris bulat', '1 biji'),
('1002', '2', 'Goreng ayam yang tel'),
('1002', '3', 'Gunakan minyak mengg'),
('1002', '4', 'Masukkan kicap, cili'),
('1002', '5', 'Masukkan ayam dan ka'),
('1002', '6', 'Masak sehingga bawan'),
('1003', 'ayam', '1/2 ekor'),
('1003', 'rempah sup', '1 paket'),
('1003', 'kentang', '2 biji'),
('1003', 'carrot', '1/2 batang'),
('1003', 'saderi', '2 batang'),
('1003', 'garam', 'secukup rasa'),
('1003', 'air', '6 gelas'),
('1003', 'bawang merah-kisar', '3 ulas'),
('1003', 'bawang putih-kisar', '2 ulas'),
('1003', 'halia-kisar', '1 inci'),
('1003', 'daun sup', 'ikut suka'),
('1003', 'bawang goreng', 'ikut suka'),
('1004', 'ayam-perap', '1/2 ekor'),
('1004', 'cili padi hijau', '8-9 tangkai'),
('1004', 'cili padi merah', '3 tangkai'),
('1004', 'bawang holland-tumbu', '1 biji'),
('1004', 'bawang putih-tumbuk', '2 ulas'),
('1004', 'tomato-potong dadu', '1 biji'),
('1004', 'garam', 'secukup rasa'),
('1005', 'ayam', '1/2 ekor'),
('1005', 'kentang-belah 4', '2 biji'),
('1005', 'bawang merah-kisar', '2 biji'),
('1005', 'bawang putih-kisar', '3 ulas'),
('1005', 'tomato-belah 4', '1 biji'),
('1005', 'daun kari', '3 tangkai'),
('1005', 'halia-kisar', '2 inci'),
('1005', 'air', 'secukupnya'),
('1005', 'serbuk kari', '4 sudu besar'),
('1005', 'serbuk cili', '2 sudu besar'),
('1005', 'garam', 'secukup rasa');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
