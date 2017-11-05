#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include "moviesdb.h"
#include <cstdlib>

mysqlpp::Connection myDB;

mysqlpp::Query connect() {
    // Connect to database with: database, server, userID, password
    
    myDB = mysqlpp::Connection("cse381", "localhost", "cse381", "m1am1");
    // Create a query 
    mysqlpp::Query query = myDB.query();

    return myDB.query();
}


void getMovieListing(std::vector<std::string> &movies) {
	mysqlpp::Query query = myDB.query();
	query << "SELECT title FROM movies";
	query.parse();
	mysqlpp::StoreQueryResult movieList = query.store();
	for(size_t row = 0; row < movieList.size(); row++){
		std::string title = movieList[row][0].c_str();
		movies.push_back(title);
	}	
}

void getMovieInfo(const char * path, std::string &buf) {
	mysqlpp::Query query = myDB.query();
	query << "SELECT * FROM movies "
	      << "WHERE title = " << buf;	
	mysqlpp::StoreQueryResult info = query.store();
	if(info == NULL){
		std::cout << "Sorry the movie you are looking for could not be found." << std::endl;
	} else{
		//creating variables associated to table fields
		int budget = info[0][2];
		std::string genre = info[0][3].c_str();
		std::string homepage = info[0][4].c_str();
		std::string keywords = info[0][5].c_str();
		std::string oriLang = info[0][6].c_str();
		std::string oriTitle = info[0][7].c_str();
		std::string overview = info[0][8].c_str();
		int popularity = info[0][9];
		std::string prodCompanies = info[0][10].c_str();
		std::string prodCountries = info[0][11].c_str();
		std::string releaseDate = info[0][12].c_str();
		int revenue = info[0][13];
		int runtime = info[0][14];
		std::string spokLang = info[0][15].c_str();
		std::string tagline = info[0][16].c_str();
		std::string title = info[0][17].c_str();
		int voteAvg = info[0][18];
		int voteCount = info[0][19];
		std::string comments = info[0][1].c_str();		

		//printing out variables
		std::cout << "Title: " << title << std::endl;
		std::cout << "Budget: $" << budget << std::endl;
		std::cout << "HomePage: " << homepage << std::endl;
		std::cout << "Keywords: " << keywords << std::endl;
		std::cout << "Original Language: " << oriLang << std::endl;
		std::cout << "Original Title: " << oriTitle << std::endl;
		std::cout << "Overview: " << overview << std::endl;
		std::cout << "Popularity: " << popularity << std::endl;
		std::cout << "Production Companies: " << prodCompanies << std::endl;
		std::cout << "Production Countries: " << prodCountries << std::endl;
		std::cout << "Release Date: " << releaseDate << std::endl;
		std::cout << "Revenue: " << revenue << std::endl;
		std::cout << "Runtime: " << runtime << std::endl;
		std::cout << "Spoken Language: " << spokLang << std::endl;
		std::cout << "Tagline: " << tagline << std::endl;
		std::cout << "Vote Average: " << voteAvg << std::endl;
		std::cout << "Vote Count: " << voteCount << std::endl;
		std::cout << "Comments: " << comments << std::endl;
	}	
}

void addComment(std::string title, std::string comment){
	mysqlpp::Query query = myDB.query();
	query << "SELECT title, comments "
	      << "FROM movies "
	      << "WHERE title = " << title;
	mysqlpp::StoreQueryResult result = query.store();
	if(result.size() > 1){
		std::cout << "Sorry we could not find the movie you where lookin for." << std::endl;
	} else{
		std::string oldComment = result[0][1].c_str();
		query << "UPDATE movies "
		      << "IF comments IS NULL "
		      << "SET comments = " << comment
		      << " WHERE title = " << title
		      << " ELSE "
		      << "SET comments = " << oldComment << "\n\n" << comment
		      << " WHERE title = " << title;
	}
}

