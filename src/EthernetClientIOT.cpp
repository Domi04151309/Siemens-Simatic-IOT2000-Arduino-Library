/*
 *IOT2000 - Library for the Siemens Simatic IOT2000
 *
 *Copyright 2018 Dominik Reichl
 *
 *Developed by Dominik Reichl
 *
 *This library is free software; you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation; either version 2 of the License, or
 *(at your option) any later version.
 *
 *This library is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this library; if not, write to the Free Software
 *Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *As a special exception, you may use this file as part of a free software
 *library without restriction.  Specifically, if other files instantiate
 *templates or use macros or inline functions from this file, or you compile
 *this file and link it with other files to produce an executable, this
 *file does not by itself cause the resulting executable to be covered by
 *the GNU General Public License.  This exception does not however
 *invalidate any other reasons why the executable file might be covered by
 *the GNU General Public License.
 */

#include <Arduino.h>
#include <EthernetClientIOT.h>

#include <fstream> 

EthernetClientIOT::EthernetClientIOT(){}

void EthernetClientIOT::standardHttpResponseHeader(EthernetClient client){
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
}

void EthernetClientIOT::loadHTML(char* location,EthernetClient client){
	std::ifstream infile;
	infile.open(location);
	if(!infile){
		client.println("Can't open file!");
	}else{
		while(infile.getline(z, 255)){
			client.println(z); 
			checkFunction(client);
		}
		infile.close();
	}	
}

void EthernetClientIOT::checkFunction(EthernetClient client){
	if(checkFunction2(z,256,"digitalRead(0)",14)){
		client.println(digitalRead(0));
	}else if(checkFunction2(z,256,"digitalRead(1)",14)){
		client.println(digitalRead(1));
	}else if(checkFunction2(z,256,"digitalRead(2)",14)){
		client.println(digitalRead(2));
	}else if(checkFunction2(z,256,"digitalRead(3)",14)){
		client.println(digitalRead(3));
	}else if(checkFunction2(z,256,"digitalRead(4)",14)){
		client.println(digitalRead(4));
	}else if(checkFunction2(z,256,"digitalRead(5)",14)){
		client.println(digitalRead(5));
	}else if(checkFunction2(z,256,"digitalRead(6)",14)){
		client.println(digitalRead(6));
	}else if(checkFunction2(z,256,"digitalRead(7)",14)){
		client.println(digitalRead(7));
	}else if(checkFunction2(z,256,"digitalRead(8)",14)){
		client.println(digitalRead(8));
	}else if(checkFunction2(z,256,"digitalRead(9)",14)){
		client.println(digitalRead(9));
	}else if(checkFunction2(z,256,"digitalRead(10)",15)){
		client.println(digitalRead(10));
	}else if(checkFunction2(z,256,"digitalRead(11)",15)){
		client.println(digitalRead(11));
	}else if(checkFunction2(z,256,"digitalRead(12)",15)){
		client.println(digitalRead(12));
	}else if(checkFunction2(z,256,"digitalRead(13)",15)){
		client.println(digitalRead(13));
	}else if(checkFunction2(z,256,"analogRead(A0)",14)){
		client.println(analogRead(A0));
	}else if(checkFunction2(z,256,"analogRead(A1)",14)){
		client.println(analogRead(A1));
	}else if(checkFunction2(z,256,"analogRead(A2)",14)){
		client.println(analogRead(A2));
	}else if(checkFunction2(z,256,"analogRead(A3)",14)){
		client.println(analogRead(A3));
	}else if(checkFunction2(z,256,"analogRead(A4)",14)){
		client.println(analogRead(A4));
	}else if(checkFunction2(z,256,"analogRead(A5)",14)){
		client.println(analogRead(A5));
	}
}

bool EthernetClientIOT::checkFunction2(char input[],int len_text,char searched[],int len_search){
	textFound=false;
	pos_search=0;
  pos_text=0;
  for (pos_text = 0; pos_text < len_text - len_search;++pos_text){
    if(input[pos_text] == searched[pos_search]){
      ++pos_search;
      if(pos_search == len_search){
				textFound=true;
				return true;
      }
    }else{
      pos_text -=pos_search;
      pos_search = 0;
    }
  }
	if(!textFound){
		return false;
	}
}