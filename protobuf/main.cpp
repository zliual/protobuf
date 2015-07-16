#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
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

	std::ofstream out("out.txt", std::ofstream::binary);
	out << stu_str;
	stu_test.SerializeToOstream(&out);
	out.close();
	
	Student stu_in;
	std::string msg;
	std::ifstream in("out.txt", std::ofstream::binary);
	in >> msg;

	//std::cout<<"original: "<<stu_str.size()<<", "<< stu_str<<", post: "<<msg.size()<<", "<< msg <<std::endl;

/*
	Student stu_parse;
	if(stu_parse.ParseFromString(stu_str)){
		std::cout<<"parsing good!"<<std::endl;
		std::cout<<"length: "<<stu_str.size()<<std::endl;
		std::cout<<"id: "<< stu_parse.id() <<", name: " << stu_parse.name() <<", age: "<< stu_parse.age() <<std::endl;
	}
*/
	
	//std::cout<<msg<<std::endl;
	//if(stu_in.ParseFromString(msg)){std::cout<<"good!"<<std::endl;}
/*	if(stu_in.ParseFromIstream(&in)){
		std::cout<<"good!"<<std::endl;
		std::cout<<"id: "<< stu_in.id() <<", name: " << stu_in.name() <<", age: "<< stu_in.age() <<std::endl;
	}*/
	
	/*
	if(stu_in.ParseFromString(msg)){
		std::cout<<"id: "<< stu_in.id() <<", name: " << stu_in.name() <<", age: "<< stu_in.age() <<std::endl;
	}
*/
	in.close();
	google::protobuf::ShutdownProtobufLibrary();

	return 1;
}
