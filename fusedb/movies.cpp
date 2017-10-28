#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include "moviesdb.h"
#include <cstdlib>

mysqlpp::Query connect() {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse381", "localhost", "cse381", "m1am1");
    // Create a query 
    mysqlpp::Query query = myDB.query();

    return myDB.query();
}


void getMovieListing(std::vector<std::string> &movies) {
	mysql::Query query = myDB.query();
	query << "SELECT title FROM movies";
	query.parse();
	mysql::StoreQueryResult movieList = query.store();
	for(int row = 0; row < movieList.getRowCount(); <row++){
		std::string title = movieList[row][0].c_str();
		movies.push_back(title);
	}	
}

void getMovieInfo(const char * path, std::string &buf) {
	mysql::Query query = myDB.query();
	query << "SELECT * FROM movies";
	      << "WHERE title = '" <<buf "'";	
	mysql::StoreQueryResult info = query.store();
	if(info.isnull()){
		std::cout << "Sorry the movie you are looking for could not be found." << std::endl;
	} else{
		int budget = info[0][1];
		std::string genre = info[0][2].c_str();
	}	
}




