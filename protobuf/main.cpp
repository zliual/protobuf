#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include "student.pb.h"

int main(int argc, char** argv){
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	Student stu_test;
	std::cout<<"created!"<<std::endl;
	
	stu_test.set_name("Bob");
	stu_test.set_id("007");
	stu_test.set_age(26);

	std::string stu_str;
	stu_test.SerializeToString(&stu_str);
	std::stringstream ss;
	ss << stu_str;
	if(ss.str()==stu_str){std::cout<<"equal"<<std::endl;}
	
	std::ofstream out("out.txt", std::ofstream::binary);
	//out << stu_str;
	if(!stu_test.SerializeToOstream(&out)){
		std::cerr<<"failed to write..."<<std::endl;
		return -1;
	}
	out.close();
	
	Student stu_in;
	//std::string msg;
	std::ifstream in("out.txt", std::ofstream::binary);
	//in >> msg;


	if(stu_in.ParseFromIstream(&in)){
		std::cout<<"good!"<<std::endl;
		std::cout<<"id: "<< stu_in.id() <<", name: " << stu_in.name() <<", age: "<< stu_in.age() <<std::endl;
	}
	else{
		std::cerr<<"failed to read..."<<std::endl;
	}
	in.close();	
	/*
	if(stu_in.ParseFromString(msg)){
		std::cout<<"id: "<< stu_in.id() <<", name: " << stu_in.name() <<", age: "<< stu_in.age() <<std::endl;
	}
	*/

	google::protobuf::ShutdownProtobufLibrary();

	return 1;
}
