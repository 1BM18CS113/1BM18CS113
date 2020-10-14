#!/bin/bash
users=$(who|wc - l)
echo "$users"