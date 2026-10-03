all: ./a.out

compRun:
	g++ -g -std=c++11 main.cpp Address.cpp MedicalCenter.cpp PersonInfo.cpp Petinfo.cpp Pet.cpp VetClinic.cpp Disease.cpp PatientHistory.cpp Date.cpp Cat.cpp -o r.out

compTest:
	g++ -g -std=c++11 main.cpp Address.cpp MedicalCenter.cpp PersonInfo.cpp Disease.cpp PatientHistory.cpp Patient.cpp Doctor.cpp Dead.cpp Morgue.cpp Appointment.cpp Room.cpp Pharmacist.cpp Pharmacy.cpp Billing.cpp Medicine.cpp Prescription.cpp Petinfo.cpp Pet.cpp VetClinic.cpp Parking.cpp Visitor.cpp Emergency.cpp Hospital.cpp Department.cpp Cardiology.cpp -o a.out

test: clean compTest; ./a.out

run: clean compRun; ./r.out

clean:
	rm -f *.out