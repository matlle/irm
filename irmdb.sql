-- MySQL dump 10.14  Distrib 5.5.33-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: irm
-- ------------------------------------------------------
-- Server version	5.5.33-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `batiment`
--

DROP TABLE IF EXISTS `batiment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `batiment` (
  `batiment_id` int(6) unsigned NOT NULL AUTO_INCREMENT,
  `batiment_name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`batiment_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `batiment`
--

LOCK TABLES `batiment` WRITE;
/*!40000 ALTER TABLE `batiment` DISABLE KEYS */;
/*!40000 ALTER TABLE `batiment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chambre`
--

DROP TABLE IF EXISTS `chambre`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chambre` (
  `chambre_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `chambre_name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`chambre_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chambre`
--

LOCK TABLES `chambre` WRITE;
/*!40000 ALTER TABLE `chambre` DISABLE KEYS */;
/*!40000 ALTER TABLE `chambre` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `resident`
--

DROP TABLE IF EXISTS `resident`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `resident` (
  `resident_id` int(11) NOT NULL AUTO_INCREMENT,
  `resident_nom` varchar(50) DEFAULT NULL,
  `resident_prenom` varchar(50) DEFAULT NULL,
  `resident_email` varchar(50) DEFAULT NULL,
  `resident_phone_number` varchar(50) DEFAULT NULL,
  `type_resident_id` int(11) DEFAULT NULL,
  `resident_photo_name` text,
  `resident_lieu_naissance` varchar(50) DEFAULT NULL,
  `resident_genre` varchar(10) DEFAULT NULL,
  `resident_taille` int(11) DEFAULT NULL,
  `resident_matricule` varchar(50) DEFAULT NULL,
  `resident_phone_number2` varchar(50) DEFAULT NULL,
  `resident_phone_number3` varchar(50) DEFAULT NULL,
  `resident_date_naissance` varchar(15) DEFAULT NULL,
  `resident_profession` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`resident_id`)
) ENGINE=InnoDB AUTO_INCREMENT=105 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `resident`
--

LOCK TABLES `resident` WRITE;
/*!40000 ALTER TABLE `resident` DISABLE KEYS */;
INSERT INTO `resident` VALUES (96,'Babo','Koukougnon Martial','paso.175@gmail.com','41-87-07-68',15,'img/uploads/userphoto/a9268268_fcb4_4956_8865_cfed2316cef4_2048982377.png','Abidjan (Adjame)','Homme',173,'CRX0001','07-08-68-98','54-57-87-42','06/06/1991','Etudiant'),(97,'Babo','Ange Fabrice','','---',13,'img/uploads/userphoto/8bbc56f1_7e04_4e8e_b1c5_2969d7414f51_1299150056.png','Abidjan (Adjame)','Homme',171,'','---','---','25/05/1993',''),(98,'Kouamelan','Assemian Christian','','---',13,'img/uploads/userphoto/95b13814_6279_4929_b197_4a0363a314c2_2120635336.png','Bonoua','Homme',167,'CRX0001','---','---','30/05/1992','Etudiant'),(99,'Femme','Femme noire femme africaine','','---',13,'img/uploads/userphoto/c993079f_11cf_4b79_b9ef_13b5e9c3d1e1_352609852.png','','Femme',178,'','---','---','01/01/2000',''),(100,'Attimini','Jean Bertrand Aristide','ajba@email.com','02-15-13-52',14,'img/uploads/userphoto/d8074992_ebe0_490d_a4e0_0ef7a0a4c474_1320597450.png','Bonoua','Homme',155,'09093733v','55-39-41-47','01-10-77-06','01/01/2000','Lycéen'),(101,'Drogba','Jean Ives Didier','','---',13,'img/uploads/userphoto/95db4419_d2ae_4bef_b79a_1e01abc2057f_458283726.png','Gagnoa','Homme',180,'','---','---','22/07/1969','Footballer'),(102,'Marley','Bob','','---',13,'img/uploads/userphoto/318faa76_6aed_48b9_8a45_f5a096045eae_204455979.png','Jamaica (Kingston)','Homme',175,'','---','---','21/01/1970','Artist chanteur'),(103,'Kakachi','Jackis','','---',15,'img/uploads/userphoto/afc3148d_6b18_4883_b31a_6272d4b2615d_1909249373.png','Tabou','Homme',180,'','---','---','09/04/1984','Planteur'),(104,'Koua','Myriam','','---',13,'','Abidjan','Femme',168,'','---','---','21/09/1993','');
/*!40000 ALTER TABLE `resident` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `type_resident`
--

DROP TABLE IF EXISTS `type_resident`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `type_resident` (
  `type_resident_id` int(11) NOT NULL AUTO_INCREMENT,
  `type_resident_name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`type_resident_id`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `type_resident`
--

LOCK TABLES `type_resident` WRITE;
/*!40000 ALTER TABLE `type_resident` DISABLE KEYS */;
INSERT INTO `type_resident` VALUES (13,'Etudiant'),(14,'Eleve'),(15,'Professionnel'),(16,'Autre');
/*!40000 ALTER TABLE `type_resident` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-01-16 16:05:04
