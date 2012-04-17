#
# Copyright 2012 Free Software Foundation, Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

archs = list()
arch_dict = dict()

#TODO enable this when we are ready
create_unaligned_archs = False

class arch_class:
    def __init__(self, flags, checks, **kwargs):
        for key, cast, failval in (
            ('name', str, None),
            ('environment', str, None),
            ('include', str, None),
            ('alignment', int, 1)
        ):
            try: setattr(self, key, cast(kwargs[key]))
            except: setattr(self, key, failval)
        self.checks = checks
        assert(self.name)
        self.flags = flags

    def __repr__(self): return self.name

def register_arch(**kwargs):
    arch = arch_class(**kwargs)
    archs.append(arch)
    arch_dict[arch.name] = arch
    if arch.alignment > 1 and create_unaligned_archs:
        kwargs['name'] += '_u'
        kwargs['alignment'] = 1
        register_arch(**kwargs)

########################################################################
# register the arches
########################################################################
#TODO skip the XML and put it here
from xml.dom import minidom
import os
gendir = os.path.dirname(__file__)
archs_xml = minidom.parse(os.path.join(gendir, 'archs.xml')).getElementsByTagName('arch')
for arch_xml in archs_xml:
    kwargs = dict()
    for attr in arch_xml.attributes.keys():
        kwargs[attr] = arch_xml.attributes[attr].value
    for node in arch_xml.childNodes:
        try:
            name = node.tagName
            val = arch_xml.getElementsByTagName(name)[0].firstChild.data
            kwargs[name] = val
        except: pass
    checks = []
    for check_xml in arch_xml.getElementsByTagName("check"):
        name = check_xml.attributes["name"].value
        params = list()
        for param_xml in check_xml.getElementsByTagName("param"):
            params.append(param_xml.firstChild.data)
        checks.append([name, params])
    flags = []
    for flag_xml in arch_xml.getElementsByTagName("flag"):
        flags.append(flag_xml.firstChild.data)
    
    register_arch(flags=flags, checks=checks, **kwargs)

if __name__ == '__main__':
    print archs
