// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

import "./Ownable.sol";

contract Library is Ownable{
    string private lib_name;
    mapping(string => uint) internal Books;

    struct Book {
        string isbn;
        string title;
        string author;
    }

    constructor(string memory _libraryName) onlyOwner(){
        lib_name = _libraryName;
    }
}