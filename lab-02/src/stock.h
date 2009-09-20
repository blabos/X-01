/*
 * stock.h
 *
 *  Created on: Sep 19, 2009
 *      Author: blabos
 */

#ifndef STOCK_H_
#define STOCK_H_

typedef struct {
	int rice;
	int bean;
	int corn;
	int milk;
	int wine;
} stock_t;


void stock_init();
void stock_reload();

int stock_rice();
int stock_bean();
int stock_corn();
int stock_milk();
int stock_wine();

int stock_request_rice(int quant);
int stock_request_bean(int quant);
int stock_request_corn(int quant);
int stock_request_milk(int quant);
int stock_request_wine(int quant);


#endif /* STOCK_H_ */
