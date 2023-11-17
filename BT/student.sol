// SPDX-License-Identifier: MIT
pragma solidity 0.8;

contract studentdata{
    struct student{
        uint age;
        string name;
    }

    student[] public arr;

    function addstudent(uint age,string memory name) public{
        for(uint i=0;i<arr.length;i++)
        {
            if(arr[i].age == age){
                revert("Roll exists");
            }
        }
        arr.push(student(age,name));
    }

    function displayAllStudents() public view returns (student[] memory) {
        return arr;
    }

    function getStudentLength() public view returns (uint256) {
        return arr.length;
    }

    function getStudent(uint128 index) public view returns (student memory) {
        require(arr.length > index, "Out of Index");
        return arr[index];
    }
}
