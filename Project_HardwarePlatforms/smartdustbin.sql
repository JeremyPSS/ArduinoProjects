CREATE OR REPLACE TABLE tacho(
	idtacho INT NOT null,
  	contar INT NOT null,
	CONSTRAINT pk_idtacho PRIMARY KEY (idtacho)
);

INSERT INTO tacho (idtacho,contar) VALUES(1,1);