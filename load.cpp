#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int i=0;
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}














void fun(string filename,int tableno)
{
    ifstream myfile(filename.c_str());
    
    if (myfile.is_open())
    {
        
        string line;
        
        sqlite3 *db;
        char *zErrMsg = 0;
        int  rc;
        char *sql;
        //char *sql5;
        
        // Open database
        rc = sqlite3_open("nutrients.db", &db);
        if( rc ){
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            //return(0);
        }else{
            ;
            //fprintf(stdout, "Opened database successfully\n");
        }
        
        
        // Create SQL statement
        if(tableno==4)
        {
            sql= "DROP TABLE IF EXISTS FOOD_DES ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
          
            sql = "CREATE TABLE FOOD_DES("  \
            "NDB_No               TEXT PRIMARY KEY   NOT NULL," \
            "FdGrp_Cd           TEXT    NOT NULL," \
            "Long_Desc           TEXT    NOT NULL," \
            "Shrt_Desc           TEXT    NOT NULL," \
            "ComName           TEXT    ," \
            "ManufacName           TEXT    ," \
            "Survey           TEXT    ," \
            "Ref_desc           TEXT    ," \
            "Refuse           INT(2)    ," \
            "SciName           TEXT    ," \
            "N_Factor           DECIMAL(4,2)    ," \
            "Pro_Factor           DECIMAL(4,2)    ," \
            "Fat_Factor           DECIMAL(4,2)   ," \
            "CHO_Factor           DECIMAL(4,2)    );";
        }
        if(tableno ==5)
        {
            sql= "DROP TABLE IF EXISTS FD_GROUP ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
            
            sql = "CREATE TABLE FD_GROUP("  \
            "FdGrp_Cd             TEXT PRIMARY KEY     NOT NULL," \
            "FdGrp_Desc           TEXT     NOT NULL);" ;
        }
        if(tableno == 6)
        {
         
            sql= "DROP TABLE IF EXISTS LANGUAL ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
            
        sql = "CREATE TABLE LANGUAL("  \
            "NDB_No             TEXT         NOT NULL," \
            "Factor_Code           TEXT     NOT NULL,"\
            "PRIMARY KEY (NDB_No,Factor_Code) );" ;
        
        }
        
        if(tableno == 7)
        {
            sql= "DROP TABLE IF EXISTS LANGDESC ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
            
            sql = "CREATE TABLE LANGDESC("  \
            "Factor_Code             TEXT PRIMARY KEY     NOT NULL," \
            "Description           TEXT     NOT NULL);" ;
        
        }
        
        if(tableno==8)
        {
            sql= "DROP TABLE IF EXISTS NUT_DATA ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
            
        sql = "CREATE TABLE NUT_DATA("  \
            "NDB_No            TEXT     NOT NULL," \
            "Nutr_No           TEXT    NOT NULL," \
            "Nutr_Val           DECIMAL(10,3)    NOT NULL," \
            "Num_Data_Pts           DECIMAL(5,0)    NOT NULL," \
            "Std_Error           DECIMAL(8,3)    ," \
            "Src_Cd           TEXT     NOT NULL," \
            "Survey           TEXT    ," \
            "Deriv_Cd           TEXT    ," \
            "Ref_NDB_No           TEXT    ," \
            "Add_Nutr_Mark           TEXT    ," \
            "Num_Studies           INT(2)    ," \
            "Min           DECIMAL(10,3)    ," \
            "Max           DECIMAL(10,3)   ," \
            "DF           INT(4)    ," \
            "Low_EB           DECIMAL(10,3)    ," \
            "Up_EB           DECIMAL(10,3)    ," \
            "Stat_cmt           TEXT   ," \
            "AddMod_Date           TEXT   ," \
            "CC          TEXT    ,"\
            "PRIMARY KEY (NDB_No,Nutr_No) );" ;
        
        }
        
        if(tableno == 9)
        {
            sql= "DROP TABLE IF EXISTS NUTR_DEF ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        
            sql = "CREATE TABLE NUTR_DEF("  \
            "Nutr_No             TEXT PRIMARY KEY     NOT NULL," \
            "Units             TEXT     NOT NULL," \
            "Tagname             TEXT     ," \
            "NutrDesc             TEXT     NOT NULL," \
            "Num_Dec            TEXT     NOT NULL," \
            "SR_Order           INT(6)     NOT NULL);" ;
        
        }
        if(tableno == 10)
        {
            sql= "DROP TABLE IF EXISTS SRC_CD ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
            
            sql = "CREATE TABLE SRC_CD ("  \
            "Src_Cd             TEXT PRIMARY KEY     NOT NULL," \
            "SrcCd_Desc           TEXT     NOT NULL);" ;
        }
        
        if(tableno == 11)
        {
            sql= "DROP TABLE IF EXISTS DERIV_CD ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
            
        sql = "CREATE TABLE DERIV_CD ("  \
            "Deriv_Cd             TEXT PRIMARY KEY     NOT NULL," \
            "Deriv_Desc           TEXT     NOT NULL);" ;
        }
        
        if(tableno == 12)
        {
            sql= "DROP TABLE IF EXISTS WEIGHT ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        
            sql = "CREATE TABLE WEIGHT ("  \
            "NDB_No             TEXT   NOT NULL," \
            "Seq             TEXT     NOT NULL," \
            "Amount             DECIMAL(5,3)     NOT NULL," \
            "Msre_Desc             TEXT     NOT NULL," \
            "Gm_Wgt            DECIMAL(7,1)    NOT NULL," \
            "Num_Data_Pts            INT(3)     ," \
            "Std_Dev           DECIMAL(7,3)   ," \
            "PRIMARY KEY (NDB_No,Seq) );" ;
        
        }
        if(tableno == 13)
        {
            sql= "DROP TABLE IF EXISTS FOOTNOTE ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        
            sql = "CREATE TABLE FOOTNOTE ("  \
            "NDB_No             TEXT   NOT NULL," \
            "Footnt_No             TEXT     NOT NULL," \
            "Footnt_Typ             DECIMAL(5,3)     NOT NULL," \
            "Nutr_No             TEXT     ," \
            "Footnt_Txt           DECIMAL(7,3)  NOT NULL );" ;
        }
        
        if(tableno == 14)
        {
            sql= "DROP TABLE IF EXISTS DATSRCLN ;";
            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        
            sql = "CREATE TABLE DATSRCLN ("  \
            "NDB_No             TEXT         NOT NULL," \
            "Nutr_No             TEXT         NOT NULL," \
            "DataSrc_ID           TEXT     NOT NULL,"\
            "PRIMARY KEY (NDB_No,Nutr_No,DataSrc_ID) );" ;
        }
        
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }else{
            ;
            //fprintf(stdout, "Table created successfully\n");
        }
        
        
        
        
        
        
        
        while ( getline (myfile,line) )
        {
            
            while(line.find("'") != std::string::npos)
                line.replace(line.find("'"), std::string("'").length(), "_");
            
            while(line.find("\"") != std::string::npos)
                line.replace(line.find("\""), std::string("\"").length(), "$");
            
            while(line.find("~~") != std::string::npos)
                line.replace(line.find("~~"), std::string("~~").length(), "NULL");
            
            while(line.find("~^~") != std::string::npos)
                line.replace(line.find("~^~"), std::string("~^~").length(), "','");
            
            while(line.find("~") != std::string::npos)
                line.replace(line.find("~"), std::string("~").length(), "'");
            
            while(line.find("^^") != std::string::npos)
                line.replace(line.find("^^"), std::string("^^").length(), "^'NULL'^");
            
            
            line.pop_back();
            line.push_back('@');
            
            if(line.find("^@") != std::string::npos)
                line.replace(line.find("^@"), std::string("^@").length(), "','NULL'");
            
            if(line.find("@") != std::string::npos)
                line.replace(line.find("@"), std::string("@").length(), "");
            
            while(line.find("^") != std::string::npos)
                line.replace(line.find("^"), std::string("^").length(), "','");
            
            while(line.find("''") != std::string::npos)
                line.replace(line.find("''"), std::string("''").length(), "'");
            
            line = line + "'";
            
            while(line.find("''") != std::string::npos)
                line.replace(line.find("''"), std::string("''").length(), "'");
            
            while(line.find("_") != std::string::npos)
                line.replace(line.find("_"), std::string("_").length(), "''");
            
            while(line.find("$") != std::string::npos)
                line.replace(line.find("$"), std::string("$").length(), "\"");
            
            while(line.find("'NULL'") != std::string::npos)
                line.replace(line.find("'NULL'"), std::string("'NULL'").length(), "NULL");
            
            string l;
            
            sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &zErrMsg);
            
            if(tableno == 4)
                l = "INSERT INTO FOOD_DES (NDB_No,FdGrp_Cd,Long_Desc,Shrt_Desc,ComName,ManufacName,Survey,Ref_desc,Refuse,SciName,N_Factor,Pro_Factor,Fat_Factor,CHO_Factor) VALUES ("+ line + "); ";
            
            if(tableno == 5)
                l = "INSERT INTO FD_GROUP (FdGrp_Cd,FdGrp_Desc) VALUES ("+ line + "); ";
            
            if(tableno == 6)
                l = "INSERT INTO LANGUAL (NDB_No,Factor_Code) VALUES ("+ line + "); ";
            
            if(tableno == 7)
                l = "INSERT INTO LANGDESC (Factor_Code,Description) VALUES ("+ line + "); ";
            
            if(tableno == 8)
                l = "INSERT INTO NUT_DATA (NDB_No,Nutr_No,Nutr_Val,Num_Data_Pts,Std_Error,Src_Cd,Deriv_Cd,Ref_NDB_No,Add_Nutr_Mark,Num_Studies,Min,Max,DF,Low_EB,Up_EB,Stat_cmt,AddMod_Date,CC) VALUES ("+ line + "); ";
            
            if(tableno == 9)
                l = "INSERT INTO NUTR_DEF (Nutr_No,Units,Tagname,NutrDesc,Num_Dec,SR_Order) VALUES ("+ line + "); ";
            
            if(tableno == 10)
                l = "INSERT INTO SRC_CD (Src_Cd,SrcCd_Desc) VALUES ("+ line + "); ";
            
            if(tableno == 11)
                l = "INSERT INTO DERIV_CD (Deriv_Cd,Deriv_Desc) VALUES ("+ line + "); ";
            
            if(tableno == 12)
                l = "INSERT INTO WEIGHT (NDB_No,Seq,Amount,Msre_Desc,Gm_Wgt,Num_Data_Pts,Std_Dev) VALUES ("+ line + "); ";
            
            if(tableno == 13)
                l = "INSERT INTO FOOTNOTE (NDB_No,Footnt_No,Footnt_Typ,Nutr_No,Footnt_Txt) VALUES ("+ line + "); ";
            
            if(tableno == 14)
                l = "INSERT INTO DATSRCLN (NDB_No,Nutr_No,DataSrc_ID) VALUES ("+ line + "); ";
            
            
            rc = sqlite3_exec(db, l.c_str(), callback, 0, &zErrMsg);
            
            // printf("%s\n",line.c_str());
            if( rc != SQLITE_OK )
            {
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                break;
                
            }
            else
            {
                
                i=i+1;
                //fprintf(stdout, "Records %d created successfully\n",i);
            }
            
            
        } 
        
        sqlite3_exec(db, "COMMIT TRANSACTION", NULL, NULL, &zErrMsg);
        
        /*
         if(tableno == 4)
         sql = "SELECT * from FOOD_DES";
         
         
         if(tableno == 5)
         sql = "SELECT * from FD_GROUP";
         
         if(tableno == 6)
         sql = "SELECT * from LANGUAL";
         
         if(tableno == 7)
         sql = "SELECT * from LANGDESC";
         
         if(tableno == 8)
         sql = "SELECT * from NUT_DATA";
         
         if(tableno == 9)
         sql = "SELECT * from NUTR_DEF";
         
         if(tableno == 10)
         sql = "SELECT * from SRC_CD";
         
         if(tableno == 11)
         sql = "SELECT * from DERIV_CD";
         
         if(tableno == 12)
         sql = "SELECT * from WEIGHT";
         
         if(tableno == 13)
         sql = "SELECT * from FOOTNOTE";
         
         if(tableno == 14)
         sql = "SELECT * from DATSRCLN";
         
         
         rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
         
         */
        myfile.close();
    }
    else 
        printf("Unable to open file \n"); 
    
    
    
    
    
    
    
}

















int main(int argc, char* argv[])
{
    
    fun("FOOD_DES.txt",4);
    fun("FD_GROUP.txt",5);
    fun("LANGUAL.txt",6);
    fun("LANGDESC.txt",7);
    fun("NUT_DATA.txt",8);
    fun("NUTR_DEF.txt",9);
    fun("SRC_CD.txt",10);
    fun("DERIV_CD.txt",11);
    fun("WEIGHT.txt",12);
    fun("FOOTNOTE.txt",13);
    fun("DATSRCLN.txt",14);
    
    
    
    return 0;
    
    
    
    
    
}
