// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Ownable {
    address internal owner;

    modifier onlyOwner() {
        require(owner == msg.sender, "Not invoked by the owner");
        _;
    }

    function getOwner() public view returns(address) {
        return owner;
    }

    constructor() {
        owner = msg.sender;
    }
}