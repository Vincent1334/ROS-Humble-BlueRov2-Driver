#!/usr/bin/env python3
"""Tritech Micron exceptions."""

__author__ = "Anass Al-Wohoush"


class PacketIncomplete(Exception):

    """Packet is incomplete."""
    pass


class PacketCorrupted(Exception):

    """Packet is corrupt."""
    pass


class SonarNotConfigured(Exception):

    """Sonar is not configured for scanning."""
    pass


class SonarNotFound(Exception):

    """Sonar port could not be found."""
    pass


class SonarNotInitialized(Exception):

    """Sonar not initialized."""
    pass


class TimeoutError(Exception):

    """Communication timed out."""
    pass