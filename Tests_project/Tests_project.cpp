#include "../proi_21l_206_projekt/Person.h"
#include "../proi_21l_206_projekt/Person.cpp"
#include "../proi_21l_206_projekt/Passenger.h"
#include "../proi_21l_206_projekt/Passenger.cpp"
#include "../proi_21l_206_projekt/CrewMember.h"
#include "../proi_21l_206_projekt/CrewMember.cpp"
#include "../proi_21l_206_projekt/check_data.h"
#include "../proi_21l_206_projekt/check_data.cpp"
#include "../proi_21l_206_projekt/convert_str_to_int.h"
#include "../proi_21l_206_projekt/convert_str_to_int.cpp"
#include "../proi_21l_206_projekt/aircraft.h"
#include "../proi_21l_206_projekt/aircraft.cpp"
#include "../proi_21l_206_projekt/flight.h"
#include "../proi_21l_206_projekt/flight.cpp"

#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testsproject
{
	TEST_CLASS(Testsproject)
	{
	public:
		// PERSON TESTS
		TEST_METHOD(TestPersonConstructor)
		{
			Person czlowiek("FNAME", "LNAME", 1, 1);
			Assert::AreEqual(czlowiek.getName(), std::string("FNAME"));
			Assert::AreEqual(czlowiek.getSurname(), std::string("LNAME"));
			Assert::AreEqual(czlowiek.getAge(), 1);
			Assert::AreEqual(czlowiek.getId(), 1);
		}

		TEST_METHOD(TestPersonSetterName)
		{
			Person czlowiek("FNAME", "LNAME", 1, 1);
			czlowiek.setName("czlowiek", "ziomek");
			Assert::AreEqual(czlowiek.getName(), std::string("czlowiek"));
			Assert::AreEqual(czlowiek.getSurname(), std::string("ziomek"));
		}

		TEST_METHOD(TestPersonSetterAge)
		{
			Person czlowiek("FNAME", "LNAME", 1, 1);
			czlowiek.setAge(123);
			Assert::AreEqual(czlowiek.getAge(), 123);
		}

		TEST_METHOD(TestPersonSetterId)
		{
			Person czlowiek("FNAME", "LNAME", 1, 1);
			czlowiek.setId(12);
			Assert::AreEqual(czlowiek.getId(), 12);
		}

		TEST_METHOD(TestPersonInvalidName)
		{
			Person czlowiek("FNAME", "LNAME", 1, 1);
			czlowiek.setName("cz1owiek", "zi0mek");
			Assert::AreEqual(czlowiek.getName(), std::string("INVALID_DATA"));
		}

		TEST_METHOD(TestPersonInvalidAge)
		{
			Person czlowiek("FNAME", "LNAME", 1, 1);
			czlowiek.setAge(-1);
			Assert::AreEqual(czlowiek.getAge(), 0);
		}

		// PASSENGER TESTS
		TEST_METHOD(TestPassenegerConstructor)
		{
			Passenger czlowiek;
			Assert::AreEqual(czlowiek.getName(), std::string("NODATA"));
			Assert::AreEqual(czlowiek.getSurname(), std::string("NODATA"));
			Assert::AreEqual(czlowiek.getAge(), 0);
			Assert::AreEqual(czlowiek.getFlightId(), 0);
			Assert::AreEqual(czlowiek.getId(), 0);
			Assert::AreEqual(czlowiek.getPlaceNum(), 0);
			Assert::IsFalse(czlowiek.getSeatClass());
		}

		TEST_METHOD(TestPassenegerSetterName)
		{
			Passenger czlowiek;
			czlowiek.setName("czlowiek", "ziomek");
			Assert::AreEqual(czlowiek.getName(), std::string("czlowiek"));
			Assert::AreEqual(czlowiek.getSurname(), std::string("ziomek"));
		}

		TEST_METHOD(TestPassenegerSetterAge)
		{
			Passenger czlowiek;
			czlowiek.setAge(123);
			Assert::AreEqual(czlowiek.getAge(), 123);
		}

		TEST_METHOD(TestPassenegerSetterId)
		{
			Passenger czlowiek;
			czlowiek.setId(12);
			Assert::AreEqual(czlowiek.getId(), 12);
		}


		TEST_METHOD(TestPassenegerSetterFlightId)
		{
			Passenger czlowiek;
			czlowiek.setFlightId(12);
			Assert::AreEqual(czlowiek.getFlightId(), 12);
		}

		TEST_METHOD(TestPassenegerSetterPlaceNum)
		{
			Passenger czlowiek;
			czlowiek.setPlaceNum(12);
			Assert::AreEqual(czlowiek.getPlaceNum(), 12);
		}

		TEST_METHOD(TestPassenegerSetterFirstClass)
		{
			Passenger czlowiek;
			czlowiek.setSeatClass(true);
			Assert::IsTrue(czlowiek.getSeatClass());
		}

		TEST_METHOD(TestPassenegerInvalidName)
		{
			Passenger czlowiek;
			czlowiek.setName("cz1owiek", "zi0mek");
			Assert::AreEqual(czlowiek.getName(), std::string("INVALID_DATA"));
		}

		TEST_METHOD(TestPassenegerInvalidAge)
		{
			Passenger czlowiek;
			czlowiek.setAge(-1);
			Assert::AreEqual(czlowiek.getAge(), 0);
		}

		TEST_METHOD(TestPassengerInvalidFlightId)
		{
			Passenger czlowiek;
			czlowiek.setFlightId(-12);
			Assert::AreEqual(czlowiek.getFlightId(), 0);
		}

		TEST_METHOD(TestPassengerInvalidPlaceNum)
		{
			Passenger czlowiek;
			czlowiek.setPlaceNum(-12);
			Assert::AreEqual(czlowiek.getPlaceNum(), 0);
		}

		TEST_METHOD(TestPassengerCarryOnWeightNegative)
		{
			Passenger czlowiek;
			czlowiek.setCarryOnWeight(-12);
			Assert::AreEqual(czlowiek.getCarrryOnWeight(), 0);
		}

		TEST_METHOD(TestPassengerCarryOnWeightOverMaximum)
		{
			Passenger czlowiek;
			// maximum weight is set for 20 [kg]
			czlowiek.setCarryOnWeight(21);
			Assert::AreEqual(czlowiek.getCarrryOnWeight(), 0);
		}

		TEST_METHOD(TestPassengerSuitcaseWeightNegative)
		{
			Passenger czlowiek;
			czlowiek.setSuitcaseWeight(-12);
			Assert::AreEqual(czlowiek.getSuitcaseWeight(), 0);
		}

		TEST_METHOD(TestPassengerSuitcaseWeightOverMaximum)
		{
			Passenger czlowiek;
			// maximum weight is set for 20 [kg]
			czlowiek.setSuitcaseWeight(21);
			Assert::AreEqual(czlowiek.getSuitcaseWeight(), 0);
		}

		// CREWMEMBER TESTS

		TEST_METHOD(TestCrewMemberRoleCaptain)
		{
			CrewMember czlowiek;
			czlowiek.setRole("captain");
			Assert::AreEqual(czlowiek.getRole(), std::string("captain"));
		}

		TEST_METHOD(TestCrewMemberRolePilot)
		{
			CrewMember czlowiek;
			czlowiek.setRole("pilot");
			Assert::AreEqual(czlowiek.getRole(), std::string("pilot"));
		}

		TEST_METHOD(TestCrewMemberRoleTechnician)
		{
			CrewMember czlowiek;
			czlowiek.setRole("technician");
			Assert::AreEqual(czlowiek.getRole(), std::string("technician"));
		}

		TEST_METHOD(TestCrewMemberRoleAssistant)
		{
			CrewMember czlowiek;
			czlowiek.setRole("assistant");
			Assert::AreEqual(czlowiek.getRole(), std::string("assistant"));
		}

		TEST_METHOD(TestCrewMemberRoleInvalid)
		{
			CrewMember czlowiek;
			czlowiek.setRole("samolot");
			Assert::AreEqual(czlowiek.getRole(), std::string("INVALID_DATA"));
		}

		// AIRCRAFT TESTS

		TEST_METHOD(TestAirplanegetNumber)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			Assert::AreEqual(samolot.getNumber(), std::string("12"));
		}

		TEST_METHOD(TestAirplanegetModel)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			Assert::AreEqual(samolot.getModel(), std::string("Boink"));
		}

		TEST_METHOD(TestAirplanesetNumber)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			samolot.setNumber("102");
			Assert::AreEqual(samolot.getNumber(), std::string("102"));
		}

		TEST_METHOD(TestAirplanesetModele)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			samolot.setModel("Fast plane");
			Assert::AreEqual(samolot.getModel(), std::string("Fast plane"));
		}

		TEST_METHOD(TestAirplanegetEcoseats)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			Assert::AreEqual(samolot.getEcoSeats(), 120);
		}

		TEST_METHOD(TestAirplanegetBusinessseats)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			Assert::AreEqual(samolot.getBusinessSeats(), 20);
		}

		TEST_METHOD(TestAirplanesetEcoseats)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			samolot.setEcoSeats(200);
			Assert::AreEqual(samolot.getEcoSeats(), 200);
		}

		TEST_METHOD(TestAirplanesetBusinessseats)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			samolot.setBusinessSeats(40);
			Assert::AreEqual(samolot.getBusinessSeats(), 40);
		}

		TEST_METHOD(TestAirplaneEcoFacility)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			vector<std::string> test;
			test.push_back(std::string("Kawunia"));
			samolot.setEcoFacilities(test);
			Assert::IsTrue(samolot.getEcoFacilities() == test);
		}

		TEST_METHOD(TestAirplaneBusinessFacility)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			vector<std::string> test;
			test.push_back(std::string("Kawunia ale lepsza"));
			samolot.setBusinessFacilities(test);
			Assert::IsTrue(samolot.getBusinessFacilities() == test);
		}

		TEST_METHOD(TestAirplaneEcoFacilityRemove)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			vector<std::string> test_sample;
			vector<std::string> test_empty;
			test_sample.push_back(std::string("Kawunia"));
			samolot.setEcoFacilities(test_sample);
			samolot.removeEcoFacility(0);
			Assert::IsTrue(samolot.getEcoFacilities() == test_empty);
		}

		TEST_METHOD(TestAirplaneBusinessFacilityRemove)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			vector<std::string> test_sample;
			vector<std::string> test_empty;
			test_sample.push_back(std::string("Kawunia lepsza"));
			samolot.setBusinessFacilities(test_sample);
			samolot.removeBusinessFacility(0);
			Assert::IsTrue(samolot.getBusinessFacilities() == test_empty);
		}

		TEST_METHOD(TestAirplaneShort)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			Assert::AreEqual(samolot.shortDescription(), std::string("Boink Num: 12"));
		}

		TEST_METHOD(TestAirplaneDescription)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			std::string description = "";
			description += "Boink Num: 12\n";
			description += "Number of eco seats: 120\n";
			description += "Number of business seats: 20\n";

			Assert::AreEqual(samolot.getDescription(), description);
		}

		TEST_METHOD(TestAirplaneDescriptionEcoFacilites)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			vector<std::string> test;
			test.push_back(std::string("Kawunia"));
			test.push_back(std::string("Ciacha"));
			samolot.setEcoFacilities(test);

			std::string description = "";
			description += "Boink Num: 12\n";
			description += "Number of eco seats: 120\n";
			description += "Number of business seats: 20\n";
			description += "Economic class facilities:\n";
			description += "-Kawunia\n";
			description += "-Ciacha\n";

			Assert::AreEqual(samolot.getDescription(), description);
		}

		TEST_METHOD(TestAirplaneDescriptionBusinessFacilites)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			vector<std::string> test;
			test.push_back(std::string("Kawunia"));
			test.push_back(std::string("Ciacha"));
			samolot.setBusinessFacilities(test);

			std::string description = "";
			description += "Boink Num: 12\n";
			description += "Number of eco seats: 120\n";
			description += "Number of business seats: 20\n";
			description += "Business class facilities:\n";
			description += "-Kawunia\n";
			description += "-Ciacha\n";

			Assert::AreEqual(samolot.getDescription(), description);
		}

		TEST_METHOD(TestAirplaneDescriptionFacilites)
		{
			Aircraft samolot("12", "Boink", 120, 20);
			vector<std::string> test_e;
			test_e.push_back(std::string("Kawunia"));
			test_e.push_back(std::string("Ciacha"));
			vector<std::string> test_b;
			test_b.push_back(std::string("Kawunia lepsza"));
			test_b.push_back(std::string("Ciacha tez lepsze"));

			samolot.setEcoFacilities(test_e);
			samolot.setBusinessFacilities(test_b);

			std::string description = "";
			description += "Boink Num: 12\n";
			description += "Number of eco seats: 120\n";
			description += "Number of business seats: 20\n";
			description += "Economic class facilities:\n";
			description += "-Kawunia\n";
			description += "-Ciacha\n";
			description += "Business class facilities:\n";
			description += "-Kawunia lepsza\n";
			description += "-Ciacha tez lepsze\n";

			Assert::AreEqual(samolot.getDescription(), description);
		}

		// FLIGHT TESTS

		TEST_METHOD(FlightInitTestDepartureTimeValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getDepartureTime(), departure_t);
		}
		TEST_METHOD(FlightInitTestDepartureTimeDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-99:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getDepartureTime(), default);
		}

		TEST_METHOD(FlightInitTestDepartureTimeEmpytString)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getDepartureTime(), default);
		}
		TEST_METHOD(FlightInitTestLandingTimeValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getLandingTime(), landing_t);
		}

		TEST_METHOD(FlightInitTestLandingTimeDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-32:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getLandingTime(), default);
		}

		TEST_METHOD(FlightInitTestLandingTimeEmpytString)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getLandingTime(), default);
		}

		TEST_METHOD(FlightInitTestDeparturePlaceValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getDeparturePlace(), departure_place);
		}

		TEST_METHOD(FlightInitTestDeparturePlaceDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "1";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getDeparturePlace(), default);
		}

		TEST_METHOD(FlightInitTestDeparturePlaceEmpytString)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getDeparturePlace(), default);
		}

		TEST_METHOD(FlightInitTestDestinationValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getDestination(), destination);
		}

		TEST_METHOD(FlightInitTestDestinationDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom1";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getDestination(), default);
		}

		TEST_METHOD(FlightInitTestDestinationEmptyString)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string default = "INVALID_DATA";
			Assert::AreEqual(test_flight.getDestination(), default);
		}

		TEST_METHOD(FlightInitTestFlightNumberValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getFlightNumber(), 1);
		}

		TEST_METHOD(FlightInitTestFlightNumberDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				-12,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getFlightNumber(), 0);
		}
		TEST_METHOD(FlightInitTestGateNumberValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getGateNumber(), 11);
		}

		TEST_METHOD(FlightInitTestGateNumberDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				-11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getGateNumber(), 0);
		}
		TEST_METHOD(FlightInitTestEcoSeatPriceValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getEcoSeatPrice(), 100);
		}

		TEST_METHOD(FlightInitTestEcoSeatPriceDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				-100,
				250
			);

			Assert::AreEqual(test_flight.getEcoSeatPrice(), 0);
		}
		TEST_METHOD(FlightInitTestBusinessSeatPriceValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getBusinessSeatPrice(), 250);
		}

		TEST_METHOD(FlightInitTestBusinessSeatPriceDefault)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				-250
			);

			Assert::AreEqual(test_flight.getBusinessSeatPrice(), 0);
		}

		TEST_METHOD(FlightTestSetPlaneValidEqualSeatsNum)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Aircraft new_plane("12", "Airbus A320", 200, 50);
			test_flight.setPlane(new_plane);

			Assert::AreEqual(test_flight.getPlane().getBusinessSeats(), new_plane.getBusinessSeats());
			Assert::AreEqual(test_flight.getPlane().getEcoSeats(), new_plane.getEcoSeats());
			Assert::AreEqual(test_flight.getPlane().getNumber(), new_plane.getNumber());
		}

		TEST_METHOD(FlightTestSetPlaneValidGreaterBusinessSeatsNum)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Aircraft new_plane("12", "Airbus A320", 201, 50);
			test_flight.setPlane(new_plane);

			Assert::AreEqual(test_flight.getPlane().getBusinessSeats(), new_plane.getBusinessSeats());
			Assert::AreEqual(test_flight.getPlane().getEcoSeats(), new_plane.getEcoSeats());
			Assert::AreEqual(test_flight.getPlane().getNumber(), new_plane.getNumber());
		}

		TEST_METHOD(FlightTestSetPlaneValidGreaterEcoSeatsNum)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Aircraft new_plane("12", "Airbus A320", 201, 50);
			test_flight.setPlane(new_plane);

			Assert::AreEqual(test_flight.getPlane().getBusinessSeats(), new_plane.getBusinessSeats());
			Assert::AreEqual(test_flight.getPlane().getEcoSeats(), new_plane.getEcoSeats());
			Assert::AreEqual(test_flight.getPlane().getNumber(), new_plane.getNumber());
		}

		TEST_METHOD(FlightTestSetPlaneValidSmallerBusinessSeatsNum)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Aircraft new_plane("12", "Airbus A320", 199, 50);
			test_flight.setPlane(new_plane);

			Assert::AreEqual(test_flight.getPlane().getBusinessSeats(), plane.getBusinessSeats());
			Assert::AreEqual(test_flight.getPlane().getEcoSeats(), plane.getEcoSeats());
			Assert::AreEqual(test_flight.getPlane().getNumber(), plane.getNumber());
		}

		TEST_METHOD(FlightTestSetPlaneValidSmallerEcoSeatsNum)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Aircraft new_plane("12", "Airbus A320", 201, 49);
			test_flight.setPlane(new_plane);

			Assert::AreEqual(test_flight.getPlane().getBusinessSeats(), plane.getBusinessSeats());
			Assert::AreEqual(test_flight.getPlane().getEcoSeats(), plane.getEcoSeats());
			Assert::AreEqual(test_flight.getPlane().getNumber(), plane.getNumber());
		}

		TEST_METHOD(FlightTestReserveAndCheckBusinessSeats)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, true);
			Assert::AreEqual(test_flight.checkBusinessSeat(test_pssngr.getPlaceNum()), true);
			test_flight.reserveSeat(test_pssngr);
			Assert::AreEqual(test_flight.checkBusinessSeat(test_pssngr.getPlaceNum()), false);
		}

		TEST_METHOD(FlightTestReserveAndCheckEcoSeats)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, false);
			Assert::AreEqual(test_flight.checkEcoSeat(test_pssngr.getPlaceNum()), true);
			test_flight.reserveSeat(test_pssngr);
			Assert::AreEqual(test_flight.checkEcoSeat(test_pssngr.getPlaceNum()), false);
		}

		TEST_METHOD(FlightTestSetCaptainValid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getCaptain().getName(), capt.getName());
			Assert::AreEqual(test_flight.getCaptain().getSurname(), capt.getSurname());
			Assert::AreEqual(test_flight.getCaptain().getAge(), capt.getAge());
			Assert::AreEqual(test_flight.getCaptain().getId(), capt.getId());

			CrewMember new_capt("FNAME", "LNAME", 19, 12, "captain");
			test_flight.setCaptain(new_capt);

			Assert::AreEqual(test_flight.getCaptain().getName(), new_capt.getName());
			Assert::AreEqual(test_flight.getCaptain().getSurname(), new_capt.getSurname());
			Assert::AreEqual(test_flight.getCaptain().getAge(), new_capt.getAge());
			Assert::AreEqual(test_flight.getCaptain().getId(), new_capt.getId());
		}

		TEST_METHOD(FlightTestSetCaptainInvalid)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Assert::AreEqual(test_flight.getCaptain().getName(), capt.getName());
			Assert::AreEqual(test_flight.getCaptain().getSurname(), capt.getSurname());
			Assert::AreEqual(test_flight.getCaptain().getAge(), capt.getAge());
			Assert::AreEqual(test_flight.getCaptain().getId(), capt.getId());

			CrewMember new_capt("FNAME", "LNAME", 19, 12, "assisstant");
			test_flight.setCaptain(new_capt);

			Assert::AreEqual(test_flight.getCaptain().getName(), capt.getName());
			Assert::AreEqual(test_flight.getCaptain().getSurname(), capt.getSurname());
			Assert::AreEqual(test_flight.getCaptain().getAge(), capt.getAge());
			Assert::AreEqual(test_flight.getCaptain().getId(), capt.getId());
		}

		TEST_METHOD(FlightTestGetFlightParams)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			std::string params = "FLIGHT PARAMETERS:\n";
			params = params + ("FLIGHT NUMBER: " + std::to_string(1) + '\n');
			params = params + ("DEPARTURE TIME: " + departure_t + '\n');
			params = params + ("DEPARTURE PLACE: " + departure_place + '\n');
			params = params + ("LANDING TIME: " + landing_t + '\n');
			params = params + ("DESTINATION: " + destination + '\n');
			params = params + ("BUSINESS SEATS NUMBER: " + std::to_string(plane.getBusinessSeats()) + '\n');
			params = params + ("BUSINESS SEAT PRICE: " + std::to_string(250) + '\n');
			params = params + ("ECO SEATS NUMBER: " + std::to_string(plane.getEcoSeats()) + '\n');
			params = params + ("ECO SEAT PRICE: " + std::to_string(100) + '\n');

			Assert::AreEqual(test_flight.getFlightParams(), params);
		}

		TEST_METHOD(FlightTestGetBoardingPassEcoClass)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, false);
			test_flight.reserveSeat(test_pssngr);
			std::string boarding_pass = "BOARDING PASS\n";
			boarding_pass += "PASSENGER ID: ";
			boarding_pass += std::to_string(12);
			boarding_pass += '\n';
			boarding_pass += "FLIGHT NUMBER: ";
			boarding_pass += std::to_string(1);
			boarding_pass += '\n';
			boarding_pass += "SEAT CLASS: eco class\n";
			boarding_pass += "SEAT NUMBER: ";
			boarding_pass += std::to_string(7);
			boarding_pass += '\n';
			boarding_pass += "GATE NUMBER: ";
			boarding_pass += std::to_string(11);
			boarding_pass += '\n';

			Assert::AreEqual(test_flight.getBoardingPass(12), boarding_pass);
		}

		TEST_METHOD(FlightTestGetBoardingPassBusinessClass)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, true);
			test_flight.reserveSeat(test_pssngr);
			std::string boarding_pass = "BOARDING PASS\n";
			boarding_pass += "PASSENGER ID: ";
			boarding_pass += std::to_string(12);
			boarding_pass += '\n';
			boarding_pass += "FLIGHT NUMBER: ";
			boarding_pass += std::to_string(1);
			boarding_pass += '\n';
			boarding_pass += "SEAT CLASS: business class\n";
			boarding_pass += "SEAT NUMBER: ";
			boarding_pass += std::to_string(7);
			boarding_pass += '\n';
			boarding_pass += "GATE NUMBER: ";
			boarding_pass += std::to_string(11);
			boarding_pass += '\n';

			Assert::AreEqual(test_flight.getBoardingPass(12), boarding_pass);
		}

		TEST_METHOD(TestCheckOnlyLettersEmpty)
		{
			// we want false if empty
			std::string temp = "";

			Assert::IsFalse(checkIfOnlyLetters(temp));
		}

		TEST_METHOD(TestCheckOnlyLettersTrue)
		{
			std::string temp = "LubimyProi";

			Assert::IsTrue(checkIfOnlyLetters(temp));
		}

		TEST_METHOD(TestCheckOnlyLettersFalse)
		{
			std::string temp = "Lubimy Proi";

			Assert::IsFalse(checkIfOnlyLetters(temp));
		}

		TEST_METHOD(TestCheckOnlyLettersWithSpice)
		{
			std::string temp = "!@#$%^&*()_+-=}{[]|<>?,./";

			Assert::IsFalse(checkIfOnlyLetters(temp));
		}

		TEST_METHOD(TestCheckDateCorrectnessTrue)
		{
			std::string temp = "2021.05.25-11:23:12";

			Assert::IsTrue(checkDateCorrectness(temp));
		}

		TEST_METHOD(TestCheckDateCorrectnessFalse_1)
		{
			std::string temp = "2021.05.25-11:23::12";

			Assert::IsFalse(checkDateCorrectness(temp));
		}

		TEST_METHOD(TestCheckDateCorrectnessFalse_2)
		{
			std::string temp = "2021.05.25-11:23:61";

			Assert::IsFalse(checkDateCorrectness(temp));
		}

		TEST_METHOD(TestCheckDateCorrectnessFalse_3)
		{
			std::string temp = "2021.05.25-11:23:-1";

			Assert::IsFalse(checkDateCorrectness(temp));
		}

		TEST_METHOD(TestCheckDateCorrectnessFalse_4)
		{
			std::string temp = "2021.05.25-25:23:11";

			Assert::IsFalse(checkDateCorrectness(temp));
		}

		TEST_METHOD(TestCheckDateCorrectnessFalse_5)
		{
			std::string temp = "2021.13.25-23:23:11";

			Assert::IsFalse(checkDateCorrectness(temp));
		}

		TEST_METHOD(TestCheckDateCorrectnessFalse_6)
		{
			std::string temp = "21.12.25-23:23:11";

			Assert::IsFalse(checkDateCorrectness(temp));
		}

		TEST_METHOD(TestCheckPositionTrueC)
		{
			std::string temp = "captain";

			Assert::IsTrue(checkPosition(temp));
		}

		TEST_METHOD(TestCheckPositionTrueP)
		{
			std::string temp = "pilot";

			Assert::IsTrue(checkPosition(temp));
		}

		TEST_METHOD(TestCheckPositionTrueT)
		{
			std::string temp = "technician";

			Assert::IsTrue(checkPosition(temp));
		}

		TEST_METHOD(TestCheckPositionTrueA)
		{
			std::string temp = "assistant";

			Assert::IsTrue(checkPosition(temp));

		}

		TEST_METHOD(TestCheckPositionTrueEmpty)
		{
			std::string temp = "";

			Assert::IsFalse(checkPosition(temp));
		}

		TEST_METHOD(TestCheckPositionTrueWrong)
		{
			std::string temp = "abs";

			Assert::IsFalse(checkPosition(temp));
		}


		TEST_METHOD(TestChangeSeatNormalBuzToEco)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, false);

			plane.setEcoSeats(100);
			plane.setBusinessSeats(100);

			test_flight.setCaptain(capt);
			test_flight.setPlane(plane);
			test_flight.reserveSeat(test_pssngr);

			test_flight.changeSeat(test_pssngr, 12, false);

			Assert::AreEqual(12, test_pssngr.getPlaceNum());
		}

		TEST_METHOD(TestChangeSeatNormalEcoToBuz)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, false);

			plane.setEcoSeats(100);
			plane.setBusinessSeats(100);

			test_flight.setCaptain(capt);
			test_flight.setPlane(plane);
			test_flight.reserveSeat(test_pssngr);

			test_flight.changeSeat(test_pssngr, 1, true);

			Assert::AreEqual(1, test_pssngr.getPlaceNum());
		}

		TEST_METHOD(TestChangeSeatNormalEcoToEco)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, false);


			plane.setEcoSeats(100);
			plane.setBusinessSeats(100);

			test_flight.setCaptain(capt);
			test_flight.setPlane(plane);
			test_flight.reserveSeat(test_pssngr);

			test_flight.changeSeat(test_pssngr, 1, true);

			Assert::AreEqual(1, test_pssngr.getPlaceNum());
		}

		TEST_METHOD(TestChangeSeatNormalBuzToBuz)
		{
			Aircraft plane("123", "Airbus A320", 200, 50);
			CrewMember capt("Name", "Surname", 33, 4, "captain");
			std::string departure_t = "2021.01.01-09:00:00";
			std::string landing_t = "2021.01.01-12:00:00";
			std::string departure_place = "Swidnik";
			std::string destination = "Radom";

			Flight test_flight(
				plane,
				capt,
				departure_t,
				landing_t,
				departure_place,
				destination,
				1,
				11,
				100,
				250
			);

			Passenger test_pssngr("FNAME", "LNAME", 19, 12, 1, 7, false);


			plane.setEcoSeats(100);
			plane.setBusinessSeats(100);

			test_flight.setCaptain(capt);
			test_flight.setPlane(plane);
			test_flight.reserveSeat(test_pssngr);

			test_flight.changeSeat(test_pssngr, 1, true);

			Assert::AreEqual(1, test_pssngr.getPlaceNum());
		}
	};
}